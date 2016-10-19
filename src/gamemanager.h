/*
   header file for class GameManager
   filename: gamemanager.h
*/
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "card.h"
/* forward declaration of classes */
// This is done to prevent other classes from knowing
// about our class's implementations
class HandIterator;
class DisplayType;
class Score;
class Hand;
class DeckType;
class Trick;

/* Player struct that stores the name */
struct Player {
	char name;
};

/* Team struct that holds players, current score, and trick count */
struct Team {
	Player players[2];
	Score* currentScore;
	int trickCount;
};

/*
Class: 		GameManager
Description:	This class represents the game manager in a card game.
   It contains theDeck, theDisplay , hands, score, V (validate), T(trick)
   leadCard, leader, turnCard, dealer, caller, alone, callingTeam,
   lastTrickWinner, currentTrump, and teams array to store the teams.
*/

class GameManager {
public:
        /*
        Name: GameManager()
        Description: Default Constructor
        Preconditions:  private data members are declared
        Postconditions:  private data members and array are initialized
        */
	GameManager();
	
	/*
        Name: ~GameManager()
        Description: Destructor
        Preconditions:  private data member pointers are declared
        Postconditions:  the dynamically allocated memory is freed
        */
	~GameManager();
	
	/*
        Name: isWon()
        Description: determines if the team has won or not
        Preconditions:  score exists
        Postconditions:  Returns true if the team has scored 10 or more points,
	                 otherwise returns false
        */
	bool isWon();
	
	/*
        Name: setDisplay( DisplayType* )
        Description: sets the display
        Preconditions:  
        Postconditions:  
        */
	void setDisplay( DisplayType* );
	
	/*
        Name: DisplayScore()
        Description: displays the score
        Preconditions:  score exists
        Postconditions:  The score is displayed
        */
	void displayScore();
	
	/*
        Name: getCardsFromHand()
        Description: Gets the cards that are in hands
        Preconditions:  hands exist
        Postconditions:  The hands is returned
        */
	Hand* getCardsFromHand() const;
	
	/*
        Name: removeCardFromHand( int, Card )
        Description: Removes the card from the hand
        Preconditions:  hands exist
        Postconditions:  The removed card from hand is returned
        */
	Card removeCardFromHand( int, Card );
	
	/*
	Name: getTrick()
	Description: returns a pointer to the trick it maintains
	Preconditions: gamemanager must be constructed
	Postconditions: the trick instance is returned
	*/
	Trick* getTrick() const;
	
	/*
        Name: setHands( Hand* )
        Description: sets the hand
        Preconditions:  hands exist, value is passed to function
        Postconditions:  
        */
	void setHands( Hand* );
	
	/*
        Name: dealHands( )
        Description: Shuffles the cards and deals them
        Preconditions:  hands and theDeck exist
        Postconditions:  The cards are shuffled and dealed to player's hands and
	                 turns the top card in the deck after the deal
        */
	void dealHands();
	
	/*
        Name: trickWinner( )
        Description: Determines the trick winner team
        Preconditions:  teams exist
        Postconditions:  The trick winner is determined and that team's trick
	                 count is incremented and place is returned
        */
	int trickWinner();
	
	/*
        Name: flipTurnCard( )
        Description: Flips the top card in the deck
        Preconditions:  turnCard and theDeck are declared
        Postconditions:  turnCard now has the top card of the deck
        */
	void flipTurnCard();
	
	/*
        Name: setTrump( Card )
        Description: sets up the trump and suit
        Preconditions:  hands, currentTrump exist and theTrump has value passed
	                to the function
        Postconditions:  same color of the suits are now set
        */
	void setTrump( Card );
	
	/*
        Name: setLastTrickWinner( int )
        Description: sets the last trick winner (player)
        Preconditions:  lastTrickWinner is declared and value passed to the
	                function
        Postconditions:  lastTrickWinner now has value of player that was passed
	                 to the function. lastTrickWinner = player.
        */
	void setLastTrickWinner( int );
	
	/*
        Name: setCallingTeam( int )
        Description: sets the calling team (team)
        Preconditions:  callingTeam is declared and value passed to the
	                function
        Postconditions:  callingTeam now has value of team that was passed
	                 to the function. callingTeam = team.
        */
	void setCallingTeam( int );
	
	/*
        Name: setDealer( int )
        Description: sets the dealer player
        Preconditions:  dealer is declared and value passed to the
	                function
        Postconditions:  dealer now has value of player that was passed
	                 to the function. dealer = player.
        */
	void setDealer( int );
	
	/*
        Name: setLeader( char )
        Description: sets the leader player
        Preconditions:  leader is declared and value passed to the
	                function
        Postconditions:  leader now has value of player that was passed
	                 to the function. leader = player.
        */
	void setLeader( char );
	
	/*
        Name: addPlayedCard( Card )
        Description: adds the played card to the trick
        Preconditions:  T is declared and value is passed to the function
        Postconditions:  The passed value x is added to the played card
        */
	void addPlayedCard( Card );
	
	/*
        Name: getTrickCount( int )
        Description: gets the trick number of the team
        Preconditions:  teams exist and value passed to the function
        Postconditions:  Returns the number of tricks of the team "index"
        */
	int getTrickCount( int ) const;
	
	/*
        Name: makeBids( )
        Description: Allows the player to make a bid and choice to go alone
        Preconditions:  theDisplay exists, there are teams and players
        Postconditions:  If the bid = 5 then alone is true otherwise alone stays
	                 false. Return value is true if there's a bid that is not 0, otherwise
	                 returns false
        */
	bool makeBids();
	
	/*
        Name: pickTrump( )
        Description: Allows the player to pick a trump and choice to go alone
        Preconditions:  theDisplay exists
        Postconditions:  Returns true if player chooses a trump that is not 'x',
	                 otherwise returns false
        */
	bool pickTrump();
	
	/*
        Name: resetHands( )
        Description: Resets the hands, deleting the previous dynamically
	             allocated memory and making a new one
        Preconditions:  hands exists
        Postconditions:  old memory freed and new memory allocated for hands
        */
	void resetHands();
	
	/*
        Name: resetTrick( )
        Description: Resets the trick, deleting the previous dynamically
	             allocated memory and making a new one
        Preconditions:  T exists
        Postconditions:  old memory freed and new memory allocated for T
        */
	void resetTrick();
	
	/*
        Name: playRound( int )
        Description: Makes a play for one round and returns the winner
        Preconditions:  theDisplay, hand exist, value passed to the function
        Postconditions:  The winner of the round is returned
        */
	int playRound( int LEADER );
	
	/*
        Name: calcPoints
        Description: determines how many points the winning team will recieve
        Preconditions: hand must played out
        Postconditions: the points are returned
        */
	int calcPoints();
	
	/*
        Name: setPoints
        Description: points are set from the driver
        Preconditions: none
        Postconditions: the points are set
        */
	void setPoints(int points);
	
	/*
        Name: valid
        Description: determines if a player's choice is valid
        Preconditions: the user must make a choice
        Postconditions: bool is returned if move is valid
        */
	bool valid(Card, Card, int);

	/*
        Name: getScore
        Description: returns the score for given class
        Preconditions: score must be initalized
        Postconditions: score is returned
        */
	int getScore( int ) const;
	
	
private:
        /* private data member declarations */
	DeckType* theDeck;		//the play deck
	DisplayType* theDisplay;	//the display
	Hand* hands;			//the player's hands
	Score* score;			//the score
	Trick* T;			//one trick
	
	Card leadCard;			//card lead by first player
	
	char leader;			//the player who lead
	Card turnCard;			//the card flipped over
	int dealer;			//the dealer of the cards
	int Caller;			//the team who called it
	bool alone;			//is the player going alone?
	int skippedPlayer;		//used when a player goes alone

	int callingTeam;		//keeps track of who called trump
	int winningTeam;		//keeps track of which team is winning
	int lastTrickWinner;		//this keeps track of who won the last trick
	char currentTrump;		//the trump
	Team teams[2];			//two teams of players
};

#endif
