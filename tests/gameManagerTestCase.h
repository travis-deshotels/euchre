#include <cppunit/extensions/HelperMacros.h>

//Testcase for the gamemanager class

class gameManagerTestCase : public CPPUNIT_NS::TestFixture {
	CPPUNIT_TEST_SUITE( gameManagerTestCase );
	CPPUNIT_TEST( testSetTrump );
	CPPUNIT_TEST( testGetTrickCount );
	CPPUNIT_TEST( testMakeBids );
	CPPUNIT_TEST( testCalcPoints );
	CPPUNIT_TEST( testValid );
	CPPUNIT_TEST( testDealHands );
	CPPUNIT_TEST( testTrickWinner );
	CPPUNIT_TEST_SUITE_END();
	
private:
	void testSetTrump();
	void testGetTrickCount();
	void testMakeBids();
	void testCalcPoints();
	void testValid();
	void testDealHands();
	void testTrickWinner();
};
