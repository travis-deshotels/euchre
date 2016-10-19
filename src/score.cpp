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

/*
   implementation file for a class Score
   filename: score.cpp
*/
#include "score.h"

Score::Score() {
        /*
        Name: Score( )
        Description: Constructor
        Preconditions:  score is declared
        Postconditions:  score is reset to 0
        */
	reset();
}

void Score::setManager( GameManager* mgr ) {
        /*
        Name: setManager( GameManager* )
        Description: Sets the game manager
        Preconditions:  gm is declared and value passed to function
        Postconditions:  gm now has a value of mgr which is a passed value 
	                 gm = mgr
        */
	gm = mgr;
}

void Score::addToScore( int points ) {
        /*
        Name: addToScore( int points );
        Description: This function increases the score by a integer passed
	   thiis function.
        Preconditions:  There is an integer points that the score needs to be
	   increased by.  
        Postconditions:  The score of this score object is increased by points. 
        */
	score += points;
}

void Score::reset() {
        /*
        Name: reset()
        Description: This function resets the score to 0
        Preconditions:  There is a score object.
        Postconditions:  The Score is set to 0.;
        */
	score = 0;
}

int Score::getScore() {
        /*
        Name: getScore()
        Description: returns the current score of this object.
        Preconditions:  There is a score object.
        Postconditions:  The current score is returned.
        */
	return score;
}
