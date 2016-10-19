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

#include "cardTestCase.h"
#include "card.h"

CPPUNIT_TEST_SUITE_REGISTRATION( cardTestCase );

void cardTestCase::testCard() {
	Card myCard( 'A', 'd', 1 );
	CPPUNIT_ASSERT( myCard.getRank() == 'A' );
	CPPUNIT_ASSERT( myCard.getSuit() == 'd' );
	CPPUNIT_ASSERT( myCard.getValue() == 1 );
}

void cardTestCase::testRank() {
	Card myCard;
	myCard.setRank( 'K' );
	CPPUNIT_ASSERT( myCard.getRank() == 'K' );
}

void cardTestCase::testSuit() {
	Card myCard;
	myCard.setSuit( 'd' );
	CPPUNIT_ASSERT( myCard.getSuit() == 'd' );
}

void cardTestCase::testValue() {
	Card myCard;
	myCard.setValue( 1 );
	CPPUNIT_ASSERT( myCard.getValue() == 1 );
}

void cardTestCase::testCompare() {
	Card card1( 'A', 's', 1 );
	Card card2( 'A', 's', 1 );
	CPPUNIT_ASSERT( card1 == card2 );
}

void cardTestCase::testEqual() {
	Card x( 'A', 'd', -10 );
	Card y = x;
	
	CPPUNIT_ASSERT( x.getRank() == y.getRank() );
	CPPUNIT_ASSERT( x.getSuit() == y.getSuit() );
	CPPUNIT_ASSERT( x.getValue() == y.getValue() );
}

void cardTestCase::testSum() {
	/*
	The overloaded sum operator, was removed as it was not needed
	*/
}

void cardTestCase::testGreater() {
	Card x( '2', 'd', 2 );
	Card y( '3', 'c', 3 );
	
	CPPUNIT_ASSERT( y > x );
}
