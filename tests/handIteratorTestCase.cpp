#include "handIteratorTestCase.h"
#include "card.h"
#include "hand.h"
#include "handiterator.h"
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION( HandIteratorTestCase );

void HandIteratorTestCase::testBegin() {
//This tests the begin function

     Hand TempHand;
     Card AceH('A', 'h', 1);
     Card KingD('A', 'd', 1);
     Card QueenC('A', 'c', 1);
     Card JackS('A', 's', 1);
     TempHand.add(AceH);
     TempHand.add(KingD);
     TempHand.add(QueenC);
     TempHand.add(JackS);
     
     HandIterator iter(&TempHand);
     iter.begin();
     //This asserts that the first card is the ace of hearts
     CPPUNIT_ASSERT( (*iter) == AceH);
}

void HandIteratorTestCase::testEnd() {
//This tests the end function
     Hand TempHand;
     Card AceH('A', 'h', 1);
     Card KingD('K', 'd', 1);
     Card QueenC('Q', 'c', 1);
     Card JackS('J', 's', 1);
     TempHand.add(AceH);
     TempHand.add(KingD);
     TempHand.add(QueenC);
     TempHand.add(JackS);
     
     HandIterator iter(&TempHand);
     HandIterator iter2(&TempHand);
     iter2.end();
     iter++;
     iter++;
     iter++;
     iter++;
     //This asserts that the iterator is at the end
     CPPUNIT_ASSERT( iter.end() == 1);     
}

void HandIteratorTestCase::testOperator1() {
//This tests the equality operator
     Hand TempHand;
     Card AceH('A', 'h', 1);
     Card KingD('K', 'd', 1);
     Card QueenC('Q', 'c', 1);
     Card JackS('J', 's', 1);
     TempHand.add(AceH);
     TempHand.add(KingD);
     TempHand.add(QueenC);
     TempHand.add(JackS);
     
     HandIterator iter(&TempHand);
     iter.begin();
     //these assert that each card is equal to itself
     CPPUNIT_ASSERT( (*iter) == AceH);
     iter++;
     CPPUNIT_ASSERT( (*iter) == KingD);
     iter++;
     CPPUNIT_ASSERT( (*iter) == QueenC);
     iter++;
     CPPUNIT_ASSERT( (*iter) == JackS);
}

void HandIteratorTestCase::testOperator2() {
     Hand TempHand;
     Card AceH('A', 'h', 1);
     Card KingD('K', 'd', 1);
     Card QueenC('Q', 'c', 1);
     Card JackS('J', 's', 1);
     TempHand.add(AceH);
     TempHand.add(KingD);
     TempHand.add(QueenC);
     TempHand.add(JackS);
     
     HandIterator iter(&TempHand);
     iter.begin();
     CPPUNIT_ASSERT( (*iter) == AceH);
     iter++;
     CPPUNIT_ASSERT( (*iter) == KingD);
     iter++;
     CPPUNIT_ASSERT( (*iter) == QueenC);
     iter++;
     CPPUNIT_ASSERT( (*iter) == JackS);
}
