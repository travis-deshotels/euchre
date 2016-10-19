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
 
#ifndef TRICK_H
#define TRICK_H

using namespace std;

//#include "trickiterator.h"
#include "gamemanager.h"

/*
Class: 		Trick
Description:	This class represents a trick in a game of euchre, 
   the four cards played by the players in each round of the game.
*/

class Trick{
public:
	friend class TrickIterator;
        /*
        Name: Trick( GameManager* )
        Description: Constructor
        Preconditions:  none
        Postconditions:  A Trick object is created with a pointer to the
	   GameManager
        */
	Trick( GameManager* );
	Trick();
	/*
        Name: ~Trick();
        Description: Default destructor
        Preconditions:  There is a Trick object.
        Postconditions:  The Trick object is destroyed.
        */
	~Trick();
	
	bool isEmpty();
	
	/*
        Name: addPlayedCard( Card playedCard)
        Description: adds a card played by a player to this trick.
        Preconditions:  There is a playedCard.
        Postconditions:  The played card is added to this Trick.
        */
	void addPlayedCard( Card playedCard);
	
	/*
        Name: returnCardsPlayed();
        Description: Returns the Hand that stores the cards that have been
	   played
        Preconditions:  There is a Trick object.
        Postconditions:  The the hand of cards played is returned.
        */
	//Hand* returnCardsPlayed();
	HandIterator createIterator();
private:

	/*
        Name: _GameManager;
        Description: Pointer to the GameManager of the Game.
	*/
	GameManager* _GameManager;
	
	/*
        Name: layoutCards;
        Description: A hand is adapted to use to keep track of the cards in
	   a trick.
	*/
	Hand* layoutCards;
};

#endif
