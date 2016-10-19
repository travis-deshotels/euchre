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

#include "handTestCase.h"
#include "card.h"
#include "hand.h"
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION( HandTestCase );

void HandTestCase::testAdd() {
//this tests the add function
//and implicitly tests the isEmpty function

   Hand test(5);
   Card myCard( 'A', 'd', 1 );
   test.add(myCard);
   CPPUNIT_ASSERT(test.isEmpty() == false);
   test.remove(myCard);
   CPPUNIT_ASSERT(test.isEmpty() == true);
}

void HandTestCase::testRemove() {
//this tests the remove function
//and implicitly tests the isEmpty function
//and implicitly tests the add function

   Hand test(5);
   Card myCard( 'A', 'd', 1 );
   test.add(myCard);
   CPPUNIT_ASSERT(test.isEmpty() == false);
   test.remove(myCard);
   CPPUNIT_ASSERT(test.isEmpty() == true);
}

void HandTestCase::testIsEmpty() {
//this tests the isEmpty function
//and implicitly tests the add function
//and implicitly tests the remove function

   Hand test(5);
   Card myCard( 'A', 'd', 1 );
   test.add(myCard);
   CPPUNIT_ASSERT(test.isEmpty() == false);
   test.remove(myCard);
   CPPUNIT_ASSERT(test.isEmpty() == true);
}

void HandTestCase::testGetNumCards() {
//this tests the getNumCards function
//and implicitly tests the add function
//and implicitly tests the remove function


   Hand test(5);
   Card myCard( 'A', 'd', 1 );
   test.add(myCard);
   CPPUNIT_ASSERT(test.getNumCards() == 1);
   test.remove(myCard);
   CPPUNIT_ASSERT(test.getNumCards() == 0);
}

void HandTestCase::testReturnCardList() {
//return cardlist was removed from our implementation
}
