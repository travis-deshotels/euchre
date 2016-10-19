/*
 * Copyright (C) 2016 Travis Deshotels
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
 //travis.deshotels at gmail

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
