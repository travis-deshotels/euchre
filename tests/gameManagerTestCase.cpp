#include "gameManagerTestCase.h"
#include "gamemanager.h"
#include "trick.h"
#include "card.h"
#include "handiterator.h"

CPPUNIT_TEST_SUITE_REGISTRATION( gameManagerTestCase );

void gameManagerTestCase::testSetTrump() {
/*
	The set trump function is really to set the left bower
	The function finds the bower, if it is in a hand, and not still in the deck
	And then changes it to be a trump suit
*/
	//these are hardcoded because they are gamemanager data members
	char currentTrump = 's';
	char sameColor;
	Card theTrump('A', 's', 14 );
	Hand hands[4];
	//this adds the left bower to a hand
	Card A( 'J', 'c', 14 );
	hands[0].add( A );
	
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
	HandIterator iter = hands[0].createIterator();
	//for each player	
	for( int i=0;i<4;i++ ) {
		iter = hands[i].createIterator();
		iter.begin();
		
		while( !iter.end() ) {
			//This is comparing try and find the left bower
			if( (*iter).getRank() == 'J')
				if( (*iter).getSuit() == sameColor ) {
					hands[i].remove(*iter);
					Card x('j', theTrump.getSuit(), 14);
					hands[i].add(x);
				}
			iter++;
		}
	}
	iter = hands[0].createIterator();
	iter.begin();
	Card temp = hands[0].remove(*iter);
	Card temp2( 'j', 's', 14 );
	//this asserts that the bower was changed
	CPPUNIT_ASSERT( temp == temp2 );
}

void gameManagerTestCase::testTrickWinner() {
/*
	This performs two tests on determining the winner of a trick
*/
	char currentTrump = 's';
	Trick theTrick(NULL);
	
	char leader;
	
	struct Team {
    	     int trickCount;
	};
    
    	Team teams[2];	
	
	leader = 'N';
	/********************************************************
	First test
	********************************************************/
	//This tests a trick without any trump
	Card A( 'A', 'd', 14 );
	theTrick.addPlayedCard( A );
	
	Card B( 'K', 'd', 13 );
	theTrick.addPlayedCard( B);
	
	Card C( 'T', 'd', 10 );
	theTrick.addPlayedCard( C );

	Card D( '9', 'd', 9 );
	theTrick.addPlayedCard( D );

	HandIterator iter = theTrick.createIterator();
	iter.begin();
	
	int valuesPlayed[4];
	int i=0;
	//this adds extra value to trump cards, and bowers
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
	int count;
	//this searchs for the highest card
	for(count=0; count<4; count++)
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
	CPPUNIT_ASSERT( place == 0 );
	/********************************************************
	Second test
	********************************************************/
	//This tests a trick containing one trump
	Trick aTrick(NULL);
		
	Card E( 'A', 'd', 14 );
	aTrick.addPlayedCard( E );
	
	Card F( 'K', 'd', 13 );
	aTrick.addPlayedCard( F );
	
	Card G( 'T', 'd', 10 );
	aTrick.addPlayedCard( G );

	Card H( '9', 's', 9 );
	aTrick.addPlayedCard( H );

	iter = aTrick.createIterator();
	iter.begin();
	
	valuesPlayed[4];
	i=0;
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
	
	highest = 0;
	place = 0;
	for(count=0; count<4; count++)
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
	CPPUNIT_ASSERT( place == 3 );
	
}

void gameManagerTestCase::testDealHands() {
	GameManager gm;
	Hand* hand;
	
	gm.dealHands();
	hand = gm.getCardsFromHand();	//get the hands from the manager
	
	CPPUNIT_ASSERT( hand->isEmpty() == false );
	//assert hand is not empty
}
	
void gameManagerTestCase::testGetTrickCount() {
/*
	This tests the get trick count function, and also
	implictly tests the trick winner function
*/
	GameManager gm;
	
	Card* card = new Card( 'J', 's', 15 );
	gm.setTrump( *card );
	gm.addPlayedCard( *card );
	delete card;
	
	card = new Card( 'j', 's', 14 );
	gm.addPlayedCard( *card );
	delete card;
	
	card = new Card( 'T', 's', 10 );
	gm.addPlayedCard( *card );
	delete card;
	
	card = new Card( 'A', 's', 13 );
	gm.addPlayedCard( *card );
	delete card;
	
	gm.setLeader( 'N' );
	gm.trickWinner();
	CPPUNIT_ASSERT( gm.getTrickCount( 0 ) == 1 );
	CPPUNIT_ASSERT( gm.getTrickCount( 1 ) == 0 );
}

void gameManagerTestCase::testMakeBids() {
/*
	This tests the make bids function
*/
	//these is arbitruly set
	Card turnCard( 'A', 'h', 14);
	char choice;
	int i=0, pickerUpper = 0, discardCard, Caller;
	bool alone = false;
	int skippedPlayer;
	int dealer = 0;
	
	GameManager gm;
	gm.dealHands();
	Hand* hands = gm.getCardsFromHand();
	
	int bid;
	bool pickedUp = false;
	while(!pickedUp && i<4) {
	//each player now has a chance to take up
	//the first player has chosen to take up and go alone
		bid = 5;
		if(bid > 2) {
		   pickedUp = true;
		   Caller = i;
		   if(bid == 5) {
		      alone = true;
		      skippedPlayer = (i + 2) % 4;
		   }
		   gm.setTrump(turnCard);
		   //this wants dealer to choose a card
		   //the dealer chooses the first card
		   discardCard = 1;
		   HandIterator iter = hands[dealer].createIterator();
	           iter.begin();
	           for( int j=0;j<discardCard-1;j++) {
		      iter++;
	           }
		   hands[dealer].remove(*iter);
		   hands[dealer].add(turnCard);
		}   
		i++;	
	}
	CPPUNIT_ASSERT( bid == 5 );
	CPPUNIT_ASSERT( pickedUp == true );
	CPPUNIT_ASSERT( Caller == 0 );
	CPPUNIT_ASSERT( alone == true );
	CPPUNIT_ASSERT( skippedPlayer == 2 );
}

void gameManagerTestCase::testCalcPoints() {
/*
	This runs six tests to determine what amount of points are given
	based on trick counts, who called trump, and if someone went alone
*/
    int value;
    int winningTeam;
    
    struct Team {
    	int trickCount;
    };
    
    Team teams[2];
        
    int Caller;
    bool alone;
    
    //*******************************************************
    //First test	
    //*******************************************************

    //This tests a team calling 3 tricks, and then taking 3 tricks
    teams[0].trickCount = 3;
    teams[1].trickCount = 2;
    
    Caller = 0;
    alone = false;
    
    
    if(teams[0].trickCount > teams[1].trickCount) {
       winningTeam = 0;
       if(Caller == 0 || Caller == 2) {
          if(teams[0].trickCount == 5) 
	     if(alone)
	        value =  4;
	     else 
	        value =  2;
	  else
	     value =  1;
       }
       else {
          value =  2;
       }
    }
    else {
       winningTeam = 1;
       if(Caller == 1 || Caller == 3) {
          if(teams[0].trickCount == 5) 
	     if(alone)
	        value =  4;
	     else 
	        value =  2;
	  else
	     value =  1;
       }
       else {
          value =  2;
       }
    }
    value =  0;

    CPPUNIT_ASSERT( value = 1 );

    //*******************************************************
    //Second test	
    //*******************************************************

    //this tests a team calling 3 tricks and then loosing
    
    teams[0].trickCount = 2;
    teams[1].trickCount = 3;
    
    Caller = 0;
    alone = false;
    
    if(teams[0].trickCount > teams[1].trickCount) {
       winningTeam = 0;
       if(Caller == 0 || Caller == 2) {
          if(teams[0].trickCount == 5) 
	     if(alone)
	        value =  4;
	     else 
	        value =  2;
	  else
	     value =  1;
       }
       else {
          value =  2;
       }
    }
    else {
       winningTeam = 1;
       if(Caller == 1 || Caller == 3) {
          if(teams[0].trickCount == 5) 
	     if(alone)
	        value =  4;
	     else 
	        value =  2;
	  else
	     value =  1;
       }
       else {
          value =  2;
       }
    }
    value =  0;

    CPPUNIT_ASSERT( value = 2 );

    //*******************************************************
    //Third test	
    //*******************************************************

    //this tests a team calling 5 tricks and alone
    //and getting it
    
    teams[0].trickCount = 5;
    teams[1].trickCount = 0;
    
    Caller = 0;
    alone = true;
    
    if(teams[0].trickCount > teams[1].trickCount) {
       winningTeam = 0;
       if(Caller == 0 || Caller == 2) {
          if(teams[0].trickCount == 5) 
	     if(alone)
	        value =  4;
	     else 
	        value =  2;
	  else
	     value =  1;
       }
       else {
          value =  2;
       }
    }
    else {
       winningTeam = 1;
       if(Caller == 1 || Caller == 3) {
          if(teams[0].trickCount == 5) 
	     if(alone)
	        value =  4;
	     else 
	        value =  2;
	  else
	     value =  1;
       }
       else {
          value =  2;
       }
    }
    value =  0;

    CPPUNIT_ASSERT( value = 4 );
    
    //*******************************************************
    //Fourth test	
    //*******************************************************

    //this tests a team calling 5 tricks and alone
    //and not getting it
    
    teams[0].trickCount = 3;
    teams[1].trickCount = 2;
    
    Caller = 0;
    alone = true;
    
    if(teams[0].trickCount > teams[1].trickCount) {
       winningTeam = 0;
       if(Caller == 0 || Caller == 2) {
          if(teams[0].trickCount == 5) 
	     if(alone)
	        value =  4;
	     else 
	        value =  2;
	  else
	     value =  1;
       }
       else {
          value =  2;
       }
    }
    else {
       winningTeam = 1;
       if(Caller == 1 || Caller == 3) {
          if(teams[0].trickCount == 5) 
	     if(alone)
	        value =  4;
	     else 
	        value =  2;
	  else
	     value =  1;
       }
       else {
          value =  2;
       }
    }
    value =  0;

    CPPUNIT_ASSERT( value = 1 );
    //*******************************************************
    //Fifth test	
    //*******************************************************

    //this tests a team calling 3 tricks
    //and making 5
    
    teams[0].trickCount = 5;
    teams[1].trickCount = 0;
    
    Caller = 0;
    alone = false;
    
    if(teams[0].trickCount > teams[1].trickCount) {
       winningTeam = 0;
       if(Caller == 0 || Caller == 2) {
          if(teams[0].trickCount == 5) 
	     if(alone)
	        value =  4;
	     else 
	        value =  2;
	  else
	     value =  1;
       }
       else {
          value =  2;
       }
    }
    else {
       winningTeam = 1;
       if(Caller == 1 || Caller == 3) {
          if(teams[0].trickCount == 5) 
	     if(alone)
	        value =  4;
	     else 
	        value =  2;
	  else
	     value =  1;
       }
       else {
          value =  2;
       }
    }
    value =  0;

    CPPUNIT_ASSERT( value = 2 );

    //*******************************************************
    //Sixth test	
    //*******************************************************

    //this tests a team calling 5 tricks and alone
    //and only making 2
    
    teams[0].trickCount = 2;
    teams[1].trickCount = 3;
    
    Caller = 0;
    alone = true;
    
    if(teams[0].trickCount > teams[1].trickCount) {
       winningTeam = 0;
       if(Caller == 0 || Caller == 2) {
          if(teams[0].trickCount == 5) 
	     if(alone)
	        value =  4;
	     else 
	        value =  2;
	  else
	     value =  1;
       }
       else {
          value =  2;
       }
    }
    else {
       winningTeam = 1;
       if(Caller == 1 || Caller == 3) {
          if(teams[0].trickCount == 5) 
	     if(alone)
	        value =  4;
	     else 
	        value =  2;
	  else
	     value =  1;
       }
       else {
          value =  2;
       }
    }
    value =  0;

    CPPUNIT_ASSERT( value = 2 );


}

void gameManagerTestCase::testValid() {
/*
	This tests whether or not a user's choice is valid.  The
	different combinations are hard coded, and test one of 
	each possibility.
*/
	GameManager gm;
	Card A( 'A', 'd', 14 );
	Card B( 'T', 'd', 10 );
	Card C( '9', 'c', 9 );
		
	bool valid;
	
	Hand* hands = new Hand(4);
	hands[0].add( B );
	Card choice;
	Card lead;
	//*******************************************************
	//First test	
	//*******************************************************
		//lead is a diamond
		//user chooses a diamond
		//this is valid
	hands[0].add( B );
	choice = B;
	lead = A;
	HandIterator iter = hands[0].createIterator();
	
	iter.begin();
	
	bool flag = false;	//assume player cannot follow suit
	while( !iter.end() ) {
		if( (*iter).getSuit() == lead.getSuit() )
			flag = true;	//player can follow suit
		iter++;	
	}
	if( flag == false )
		valid = true;
	else if( choice.getSuit() == lead.getSuit() )
		valid = true;
	else
		valid = false;
	
		
	CPPUNIT_ASSERT( valid == true );
	hands[0].remove(B);
	//*******************************************************
	//Second test
	//*******************************************************
		//lead is a diamond
		//user has no diamond
		//any choice is valid
		
	hands[0].add( C );
	choice = C;
	lead = A;
	iter = hands[0].createIterator();
	
	iter.begin();
	
	flag = false;	//assume player cannot follow suit
	while( !iter.end() ) {
		if( (*iter).getSuit() == lead.getSuit() )
			flag = true;	//player can follow suit
		iter++;	
	}
	if( flag == false )
		valid = true;
	else if( choice.getSuit() == lead.getSuit() )
		valid = true;
	else
		valid = false;
	
	CPPUNIT_ASSERT( valid == true );
	hands[0].remove(C);
	//*******************************************************
	//Third test
	//*******************************************************
		//lead is a diamond
		//user has a diamond
		//user chooses a club
		//user can follow suit
		//this is invalid
	hands[0].add( B );
	hands[0].add( C );
	choice = C;
	lead = A;
	iter = hands[0].createIterator();
	
	iter.begin();
	
	flag = false;	//assume player cannot follow suit
	while( !iter.end() ) {
		if( (*iter).getSuit() == lead.getSuit() )
			flag = true;	//player can follow suit
		iter++;	
	}
	if( flag == false )
		valid = true;
	else if( choice.getSuit() == lead.getSuit() )
		valid = true;
	else
		valid = false;
	
	CPPUNIT_ASSERT( valid == false );
}
