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
