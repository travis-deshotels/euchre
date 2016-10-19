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
