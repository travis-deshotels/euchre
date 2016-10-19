#ifndef TRICKTESTCASE_H
#define TRICKTESTCASE_H

#include <cppunit/extensions/HelperMacros.h>

//testcase for the trick class

class TrickTestCase : public CPPUNIT_NS::TestFixture { 
           CPPUNIT_TEST_SUITE( TrickTestCase );
	   CPPUNIT_TEST( testAddPlayedCard );
           CPPUNIT_TEST( testReturnCardsPlayed );
	   CPPUNIT_TEST_SUITE_END();
private:
           void testAddPlayedCard();
	   void testReturnCardsPlayed();
};
#endif
