#ifndef DECKTESTCASE_H
#define DECKTESTCASE_H

#include <cppunit/extensions/HelperMacros.h>

//Testcase for the deck class

class euchreDeckTestCase : public CPPUNIT_NS::TestFixture {
	CPPUNIT_TEST_SUITE( euchreDeckTestCase );
	CPPUNIT_TEST( testDeck );
	CPPUNIT_TEST( testShuffle );
	CPPUNIT_TEST_SUITE_END();

private:
	void testDeck();
	void testShuffle();
};
#endif
