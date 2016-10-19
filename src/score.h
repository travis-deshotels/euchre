/*
   header file for a class Score
   filename: score.h
*/
#ifndef SCORE_H
#define SCORE_H
#include "gamemanager.h"
/*
Class: 		Score
Description:	This class keeps track of a teams score in euchre.
*/

class Score {
public:
        /*
        Name: Score( )
        Description: Constructor
        Preconditions:  score is declared
        Postconditions:  score is reset to 0
        */
	Score();
	
	/*
        Name: addToScore( int points );
        Description: This function increases the score by a integer passed
	   thiis function.
        Preconditions:  There is an integer points that the score needs to be
	   increased by.  
        Postconditions:  The score of this score object is increased by points. 
        */
	void addToScore( int );
	
	/*
        Name: reset()
        Description: This function resets the score to 0
        Preconditions:  There is a score object.
        Postconditions:  The Score is set to 0.;
        */
	void reset();
	
	/*
        Name: getScore()
        Description: returns the current score of this object.
        Preconditions:  There is a score object.
        Postconditions:  The current score is returned.
        */
	int getScore();
	
	/*
        Name: setManager( GameManager* )
        Description: Sets the game manager
        Preconditions:  gm is declared and value passed to function
        Postconditions:  gm now has a value of mgr which is a passed value 
	                 gm = mgr
        */
	void setManager( GameManager* );
	
private:
	
	/*
        Name: _GameManager;
        Description: Pointer to the GameManager of the Game.
	*/
	GameManager* gm;
	
	/*
        Name: score
        Description: The score of the this class owners team.
        */
	int score;
};
#endif
