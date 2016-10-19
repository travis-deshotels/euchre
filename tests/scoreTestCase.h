#ifndef SCORETESTCASE_H
#define SCORETESTCASE_H

#include <cppunit/extensions/HelperMacros.h>

//TestCase for the score class

class scoreTestCase : public CPPUNIT_NS::TestFixture {
	CPPUNIT_TEST_SUITE( scoreTestCase );
	CPPUNIT_TEST( testScore );
	CPPUNIT_TEST( testAdd );
	CPPUNIT_TEST( testReset );
	CPPUNIT_TEST( testGetScore );
	CPPUNIT_TEST_SUITE_END();

private:
	void testScore();
	void testAdd();
	void testReset();
	void testGetScore();
};
#endif
