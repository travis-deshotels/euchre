/*
   implementation file for class GameManager
   filename: gamemanager.cpp
*/
#include "gamemanager.h"
#include "hand.h"
#include "score.h"
#include "display.h"
#include "deck.h"
#include "trick.h"
#include "factory.h"
#include "handiterator.h"

using namespace std;

GameManager::GameManager() {
        /*
        Name: GameManager()
        Description: Default Constructor
        Preconditions:  private data members are declared
        Postconditions:  private data members and array are initialized
        */
	Factory* factory;
	#ifdef BIG
		factory = new Euchre32Factory;
	#else
		factory = new EuchreFactory;
	#endif
	
	theDeck = factory->createDeck();
	theDisplay = new Display(this);
	hands = new Hand[4];
	score = new Score[2];
	score->setManager( this );
	T = new Trick( this );
	leader = 1;
		
	teams[0].players[0].name = 'S';
	teams[0].players[1].name = 'N';
	teams[0].trickCount = 0;

	teams[1].players[0].name = 'E';
	teams[1].players[1].name = 'W';
	teams[1].trickCount = 0;
}

GameManager::~GameManager() {
        /*
        Name: ~GameManager()
        Description: Destructor
        Preconditions:  private data member pointers are declared
        Postconditions:  the dynamically allocated memory is freed
        */
	delete theDeck;
	delete theDisplay;
	delete hands;
	delete score;
}

void GameManager::dealHands( ) {
        /*
        Name: dealHands( )
        Description: Shuffles the cards and deals them
        Preconditions:  hands and theDeck exist
        Postconditions:  The cards are shuffled and dealed to player's hands and
	                 turns the top card in the deck after the deal
        */
	theDeck->shuffle();
	for(int i=0;i<5;i++ )
		for(int j=0;j<4;j++ )
			hands[j].add( theDeck->pop() );
	turnCard = theDeck->pop();
}

bool GameManager::makeBids() {
        /*
        Name: makeBids( )
        Description: Allows the player to make a bid and choice to go alone
        Preconditions:  theDisplay exists, there are teams and players
        Postconditions:  If the bid = 5 then alone is true otherwise alone stays
	                 false. Return value is true if there's a bid that is not 0, otherwise
	                 returns false
        */
	theDisplay->flipCard();
	theDisplay->endl();
	theDisplay->displayCard( turnCard );
	theDisplay->endl();
	
	char choice;
	int i=0, pickerUpper = 0, discardCard;
	
	int bid;
	bool pickedUp = false;
	theDisplay->setHands();
	while(!pickedUp && i<4) {
		theDisplay->displayHandIs();
		theDisplay->displayHand(i);
		theDisplay->endl();
		theDisplay->displayPlayerNumber( i+1 );
		theDisplay->endl();
		theDisplay->displayBid();
		cin>>bid;
		if(bid > 2) {
		   pickedUp = true;
		   Caller = i;
		   if(bid == 5) {
		      alone = true;
		      skippedPlayer = (i + 2) % 4;
		   }
		   this->setTrump(turnCard);
		   theDisplay->displayDealerDiscard();
		   theDisplay->displayPlayerNumber(dealer+1);
		   theDisplay->endl();
		   theDisplay->displayHand(dealer);
		   cin >> discardCard;
		   HandIterator iter = hands[dealer].createIterator();
		   //list<Card>::iterator iter;
                   //list<Card> hand = hands[dealer].returnCardList();
	           iter.begin();
	           for( int j=0;j<discardCard-1;j++) {
		      iter++;
	           }
		   hands[dealer].remove(*iter);
		   hands[dealer].add(turnCard);
		}   
		i++;	
	}
	
	return pickedUp;
}

bool GameManager::pickTrump() {
     /*
        Name: pickTrump( )
        Description: Allows the player to pick a trump and choice to go alone
        Preconditions:  theDisplay exists
        Postconditions:  Returns true if player chooses a trump that is not 'x',
	                 otherwise returns false
     */
     bool pickedTrump = false;
     char choice, answer;   
     int i =0;
     while(!pickedTrump && i<4) {
	theDisplay->displayPlayerNumber( i+1 );
	theDisplay->pickTrump();
	choice = theDisplay->callChoice();
	if(choice != 'x') {
	   Card y( 'a', choice, 10 ); 
	   this->setTrump( y );
	   theDisplay->displayTrump( choice );
	   pickedTrump = true;
	   Caller = i;
	   cin >> answer;
	   if(answer == 'y')
	      alone = true; 
	}
	i++;
     }
    
     return pickedTrump;
}
bool GameManager::isWon() {
        /*
        Name: isWon()
        Description: determines if the team has won or not
        Preconditions:  score exists
        Postconditions:  Returns true if the team has scored 10 or more points,
	                 otherwise returns false
        */
	return( ( score[0].getScore() >= 10 ) || ( score[1].getScore() >=10 ) );
};

int GameManager::playRound( int LEADER ) {
        /*
        Name: playRound( int )
        Description: Makes a play for one round and returns the winner
        Preconditions:  theDisplay, hand exist, value passed to the function
        Postconditions:  The winner of the round is returned
        */
	//Validate val;
	//val.setManager( &gm );
	int choice;
	char rank;
	char suit;
	int winner;
	int player = LEADER - 1;
	//start playing the trick
	
        for(int i=0; i<4; i++) {
	   player  = (player + 1) % 4;
	   if((player != skippedPlayer) || !alone) {
		//get user's move
	   	bool legal = false;
	   	while( !legal ) {
			theDisplay->displayTrickIs();
			theDisplay->displayTrick();
			theDisplay->endl();
			theDisplay->endl();
			theDisplay->displayHandIs();
		        theDisplay->displayHand(player);
		   	theDisplay->endl();
	       		theDisplay->displayPlayerNumber( i+1 );
			theDisplay->endl();
	       		theDisplay->askForMove();
               		choice = theDisplay->getMove();
         		HandIterator iter = hands[player].createIterator();
	       		//list<Card>::iterator iter;
               		//list<Card> hand = hands[player].returnCardList();
	       		iter.begin();
	       		for( int j=0;j<choice-1;j++) {
		    	iter++;
	       		}
	       		
			theDisplay->endl();
	       	
	       		if( ( i == 0 ) || \
	       			( valid( *iter, leadCard, player ) ) ) {
	          		addPlayedCard( removeCardFromHand( player, (*iter) ) );
	          		legal = true;
	       		}
	       		else { 
				theDisplay->invalidChoice();
				theDisplay->endl();
			}
		   
	       		if( i == 0 )
	       			leadCard = *iter;
	    	}
	    }
	    else {
	       addPlayedCard(*(new Card('x','x',0)));
	    }  
	}
	winner = (this->trickWinner() + LEADER) % 4;
	theDisplay->displayTrickWinner( winner+1 );
	return winner;
}

Hand* GameManager::getCardsFromHand() const{
        /*
        Name: getCardsFromHand()
        Description: Gets the cards that are in hands
        Preconditions:  hands exist
        Postconditions:  The hands is returned
        */
	return hands;
}

Trick* GameManager::getTrick() const{
	return T;
};


Card GameManager::removeCardFromHand( int index, Card playedCard ) {
        /*
        Name: removeCardFromHand( int, Card )
        Description: Removes the card from the hand
        Preconditions:  hands exist
        Postconditions:  The removed card from hand is returned
        */
	return hands[ index ].remove( playedCard );
}

void GameManager::displayScore() {
        /*
        Name: DisplayScore()
        Description: displays the score
        Preconditions:  score exists
        Postconditions:  The score is displayed
        */
	//theDisplay->displayScore( score->getScore() );
}
int GameManager::getScore( int index ) const {
	return score[index].getScore();
}

void GameManager::setLeader( char player ) {
        /*
        Name: setLeader( char )
        Description: sets the leader player
        Preconditions:  leader is declared and value passed to the
	                function
        Postconditions:  leader now has value of player that was passed
	                 to the function. leader = player.
        */
	leader = player;
}
	
void GameManager::addPlayedCard( Card x ) {
        /*
        Name: addPlayedCard( Card )
        Description: adds the played card to the trick
        Preconditions:  T is declared and value is passed to the function
        Postconditions:  The passed value x is added to the played card
        */
	T->addPlayedCard( x );
}

int GameManager::trickWinner() {
        /*
        Name: trickWinner( )
        Description: Determines the trick winner team
        Preconditions:  teams exist
        Postconditions:  The trick winner is determined and that team's trick
	                 count is incremented and place is returned
        */
	//list<Card> trick;
	//trick = (T->returnCardsPlayed())->returnCardList();
	//list<Card>::iterator iter;
	HandIterator iter = T->createIterator();
	iter.begin();
	
	int valuesPlayed[4];
	int i=0;
	while( !iter.end() ){
	    valuesPlayed[i] = (*iter).getValue();
	    if((*iter).getSuit() == currentTrump)
	        valuesPlayed[i] = valuesPlayed[i] + 10;
	    if((*iter).getRank() == 'J' && (*iter).getSuit() == currentTrump)
	        valuesPlayed[i] = valuesPlayed[i] + 50;
	    if((*iter).getRank() == 'j')
	        valuesPlayed[i] = valuesPlayed[i] + 30;
	    iter++;
	    i++;
	}
	
	int highest = 0;
	int place = 0;
	for(int count=0; count<4; count++)
	    if(valuesPlayed[count] > highest) {
	       highest = valuesPlayed[count];
	       place = count;
	    }
	
	if(place == 0 || place ==2) {
	   if(leader == 'N' || leader == 'S') {
	      teams[0].trickCount++;
	   }
	   else {
	      teams[1].trickCount++;   
	   }
	}
	else {
	   if(leader == 'N' || leader == 'S') {
	      teams[1].trickCount++;
	   }
	   else {
	      teams[0].trickCount++;   
	   }
	}
	resetTrick();
	return place;

	       
}

int GameManager::calcPoints() {
    if(teams[0].trickCount > teams[1].trickCount) {
       winningTeam = 0;
       if(Caller == 0 || Caller == 2) {
          if(teams[0].trickCount == 5) 
	     if(alone)
	        return 4;
	     else 
	        return 2;
	  else
	     return 1;
       }
       else {
          return 2;
       }
    }
    else {
       winningTeam = 1;
       if(Caller == 1 || Caller == 3) {
          if(teams[0].trickCount == 5) 
	     if(alone)
	        return 4;
	     else 
	        return 2;
	  else
	     return 1;
       }
       else {
          return 2;
       }
    }
    return 0;
}

void GameManager::setPoints(int points) {
     score[winningTeam].addToScore(points);
}

int GameManager::getTrickCount( int index ) const {
        /*
        Name: getTrickCount( int )
        Description: gets the trick number of the team
        Preconditions:  teams exist and value passed to the function
        Postconditions:  Returns the number of tricks of the team "index"
        */
	return teams[index].trickCount;
}

void GameManager::flipTurnCard() {
        /*
        Name: flipTurnCard( )
        Description: Flips the top card in the deck
        Preconditions:  turnCard and theDeck are declared
        Postconditions:  turnCard now has the top card of the deck
        */
	turnCard = theDeck->pop();	
}

void GameManager::setTrump( Card theTrump ) {
        /*
        Name: setTrump( Card )
        Description: sets up the trump and suit
        Preconditions:  hands, currentTrump exist and theTrump has value passed
	                to the function
        Postconditions:  same color of the suits are now set
        */
	currentTrump = theTrump.getSuit();
	char sameColor;
	
	//find the suit of the same color as trump
	switch( theTrump.getSuit() ) {
		case 'c':	sameColor = 's';
				break;
		case 's':	sameColor = 'c';
				break;
		case 'h':	sameColor = 'd';
				break;
		case 'd':	sameColor = 'h';
	};
	//list<Card> hand;
	//list<Card>::iterator iter;
	HandIterator iter = hands[0].createIterator();
	//for each player	
	for( int i=0;i<4;i++ ) {
		//hand = hands[i].returnCardList();
		iter = hands[i].createIterator();
		iter.begin();
		
		while( !iter.end() ) {
			if( (*iter).getRank() == 'J')
				if( (*iter).getSuit() == sameColor ) {
					hands[i].remove(*iter);
					Card x('j', theTrump.getSuit(), 14);
					hands[i].add(x);
				}
		
		iter++;
		}
	}
	
}

void GameManager::resetHands() {
        /*
        Name: resetHands( )
        Description: Resets the hands, deleting the previous dynamically
	             allocated memory and making a new one
        Preconditions:  hands exists
        Postconditions:  old memory freed and new memory allocated for hands
        */
	delete hands;
	hands = new Hand[4];
}

void GameManager::setLastTrickWinner( int player ) {
        /*
        Name: setLastTrickWinner( int )
        Description: sets the last trick winner (player)
        Preconditions:  lastTrickWinner is declared and value passed to the
	                function
        Postconditions:  lastTrickWinner now has value of player that was passed
	                 to the function. lastTrickWinner = player.
        */
	lastTrickWinner = player;
}

void GameManager::setCallingTeam( int team ) {
        /*
        Name: setCallingTeam( int )
        Description: sets the calling team (team)
        Preconditions:  callingTeam is declared and value passed to the
	                function
        Postconditions:  callingTeam now has value of team that was passed
	                 to the function. callingTeam = team.
        */
	callingTeam = team;
}

void GameManager::setDealer( int player ) {
        /*
        Name: setDealer( int )
        Description: sets the dealer player
        Preconditions:  dealer is declared and value passed to the
	                function
        Postconditions:  dealer now has value of player that was passed
	                 to the function. dealer = player.
        */
	dealer = player;
}

void GameManager::resetTrick() {
        /*
        Name: resetTrick( )
        Description: Resets the trick, deleting the previous dynamically
	             allocated memory and making a new one
        Preconditions:  T exists
        Postconditions:  old memory freed and new memory allocated for T
        */
	delete T;
	T = new Trick(this);
}

bool GameManager::valid( Card choice, Card lead, int index ) {
	//Can player follow suit?
	//list<Card>::iterator iter;
	//list<Card> hand = hands[index].returnCardList();
	HandIterator iter = hands[index].createIterator();
	
	iter.begin();
	
	bool flag = false;	//assume player cannot follow suit
	while( !iter.end() ) {
		if( (*iter).getSuit() == lead.getSuit() )
			flag = true;	//player can follow suit
		iter++;	
	}
	if( flag == false )
		return true;
	else if( choice.getSuit() == lead.getSuit() )
		return true;
	else
		return false;
}
