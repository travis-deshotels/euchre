#include "deckTestCase.h"
#include "deck.h"
#include "card.h"

CPPUNIT_TEST_SUITE_REGISTRATION( euchreDeckTestCase );

void euchreDeckTestCase::testDeck() {
/*
	This tests whether the test is constructed properly
	Also the pop and isEmpty functions are tested
*/

	EuchreDeck myDeck;
	Card temp;
	
	temp = myDeck.pop();
	//this asserts that the top card is what it should be
	CPPUNIT_ASSERT( temp.getRank() == 'A' );
	CPPUNIT_ASSERT( temp.getSuit() == 's' );
	CPPUNIT_ASSERT( temp.getValue() == 14 );
	
	for ( int i=0;i<22;i++ )
		myDeck.pop();

	//this asserts that the bottom card is what it should be
	temp = myDeck.pop();
	CPPUNIT_ASSERT( temp.getRank() == '9' );
	CPPUNIT_ASSERT( temp.getSuit() == 'c' );
	CPPUNIT_ASSERT( temp.getValue() == 9 );
	
	//this asserts that the deck is now empty
	CPPUNIT_ASSERT( myDeck.isEmpty() == true );
}

void euchreDeckTestCase::testShuffle() {
//A random shuffle cannot be tested!!!
}
