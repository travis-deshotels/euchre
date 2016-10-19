#ifndef HANDITERATORTESTCASE_H
#define HANDITERATORTESTCASE_H

#include <cppunit/extensions/HelperMacros.h>

//Testcase for the hand class

class HandIteratorTestCase : public CPPUNIT_NS::TestFixture {
	CPPUNIT_TEST_SUITE( HandIteratorTestCase );
	CPPUNIT_TEST( testBegin );
	CPPUNIT_TEST( testEnd );
	CPPUNIT_TEST( testOperator1 );
	CPPUNIT_TEST( testOperator2 );
	CPPUNIT_TEST_SUITE_END();
	
private:
	void testBegin();
        void testEnd();
        void testOperator1();
        void testOperator2();
};
#endif
