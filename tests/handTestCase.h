#ifndef HANDTESTCASE_H
#define HANDTESTCASE_H

#include <cppunit/extensions/HelperMacros.h>

//Testcase for the hand class

class HandTestCase : public CPPUNIT_NS::TestFixture {
	CPPUNIT_TEST_SUITE( HandTestCase );
	CPPUNIT_TEST( testAdd );
	CPPUNIT_TEST( testRemove );
	CPPUNIT_TEST( testIsEmpty );
	CPPUNIT_TEST( testGetNumCards );
	CPPUNIT_TEST( testReturnCardList );
	CPPUNIT_TEST_SUITE_END();
	
private:
	void testAdd();
	void testRemove();
	void testIsEmpty();
	void testGetNumCards();
	void testReturnCardList();
};
#endif
