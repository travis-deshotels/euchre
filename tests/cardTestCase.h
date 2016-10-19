#ifndef CARDTESTCASE_H
#define CARDTESTCASE_H

#include <cppunit/extensions/HelperMacros.h>

//Testcase for the card class

class cardTestCase : public CPPUNIT_NS::TestFixture {
	CPPUNIT_TEST_SUITE( cardTestCase );
	CPPUNIT_TEST( testCard );
	CPPUNIT_TEST( testRank );
	CPPUNIT_TEST( testSuit );
	CPPUNIT_TEST( testValue );
	CPPUNIT_TEST( testCompare );
	CPPUNIT_TEST( testEqual );
	CPPUNIT_TEST( testSum );
	CPPUNIT_TEST( testGreater );
	CPPUNIT_TEST_SUITE_END();
	
private:
	void testCard();
	void testRank();
	void testSuit();
	void testValue();
	void testCompare();
	void testEqual();
	void testSum();
	void testGreater();
};
#endif
