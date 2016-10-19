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

#include "trickTestCase.h"
#include "hand.h"
#include "gamemanager.h"
#include "trick.h"
#include "card.h"
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION( TrickTestCase );

void TrickTestCase::testAddPlayedCard() {
/*
	This tests that a card was added to the trick
	the isEmpty function implicitly tested also
*/
   GameManager gm;
   Trick test(&gm);
   Card myCard( 'A', 'd', 1 );
   CPPUNIT_ASSERT(test.isEmpty() == true);
   
   test.addPlayedCard(myCard);
   CPPUNIT_ASSERT(test.isEmpty() == false);
}

void TrickTestCase::testReturnCardsPlayed() {
/*
	This function was removed from our implementation
	It was unneccessary, once we "fixed up" our iterators
*/
}
