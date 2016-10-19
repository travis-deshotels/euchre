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

#include "score.h"
#include "scoreTestCase.h"

CPPUNIT_TEST_SUITE_REGISTRATION( scoreTestCase );

void scoreTestCase::testScore()
//tests the constructor
{
	Score myScore;
	CPPUNIT_ASSERT( myScore.getScore() == 0 );
}

void scoreTestCase::testAdd()
//tests adding a number to the score
{
	Score myScore;
	myScore.addToScore( 2 );
	CPPUNIT_ASSERT( myScore.getScore() == 2 );
}

void scoreTestCase::testReset()
//tests the rest
{
	Score myScore;
	
	myScore.addToScore( 2 );
	CPPUNIT_ASSERT( myScore.getScore() == 2);
	
	myScore.reset();
	CPPUNIT_ASSERT( myScore.getScore() == 0);
}

void scoreTestCase::testGetScore()
//This is not really neccessary
//the getScore is implicitly tested above
{

}
