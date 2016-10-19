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
