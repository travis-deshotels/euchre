/*
 * Copyright (C) 2016 Travis Deshotels
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
 //travis.deshotels at gmail

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
