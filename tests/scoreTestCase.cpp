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
