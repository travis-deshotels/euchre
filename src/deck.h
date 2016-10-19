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
   header file for class DeckType (root class) and derived classes: Deck,
   EuchreDeck, and EuchreDeck32
   filename: deck.h
*/
#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <stdlib.h>

/*
Class: 		DeckType
Description:	This class represents a deck in a card game. Its a root class
   It contains theDeck, and a top.
*/

class DeckType {
public:
        /*
        Name: DeckType()
        Description: Default Constructor
        Preconditions:  none
        Postconditions:  none
        */
	DeckType(){};
	
	/* virtual functions */
	virtual void shuffle() =0;
	virtual bool isEmpty() const =0;
	virtual Card pop() =0;
protected:
	Card* theDeck;
	int top;
};

/*
Class: 		Deck
Description:	This class represents a 52 card deck in a card game. Its a derived class
                from DeckType. This class is not used in this project.
*/

class Deck : public DeckType {
public:
        /*
        Name: Deck()
        Description: Default Constructor
        Preconditions:  variables are declared
        Postconditions:  The decks are initialized and inserted
        */
	Deck();
	
	/*
        Name: shuffle()
        Description: Shuffles the cards in deck 
        Preconditions:  variables are declared
        Postconditions:  The cards in a deck are shuffled randomly.
        */
	void shuffle();
	
	/*
        Name: isEmpty() const
        Description: Checks if the deck is empty or not
        Preconditions:  top is declared
        Postconditions:  Returns true if the deck is empty, otherwise returns
	                 false
        */
	bool isEmpty() const;
	
	/*
        Name: pop()
        Description: Gets a copy of the top card in a deck, decrements the top and
	             returns the copy
        Preconditions:  theDeck is created, top is declared
        Postconditions:  The top is decrememnted and the deleted card is returned
        */
	Card pop();
};

/*
Class: 		EuchreDeck
Description:	This class represents a 24 card deck in a card game. Its a derived class
                from DeckType. 
*/

class EuchreDeck : public DeckType {
public:
        /*
        Name: EuchreDeck()
        Description: Default Constructor
        Preconditions:  variables are declared
        Postconditions:  The decks are initialized and inserted
        */
	EuchreDeck();
	
	/*
        Name: shuffle()
        Description: Shuffles the cards in deck 
        Preconditions:  variables are declared
        Postconditions:  The cards in a deck are shuffled randomly.
        */
	void shuffle();
	
	/*
        Name: isEmpty() const
        Description: Checks if the deck is empty or not
        Preconditions:  top is declared
        Postconditions:  Returns true if the deck is empty, otherwise returns
	                 false
        */
	bool isEmpty() const;
	
	/*
        Name: pop()
        Description: Gets a copy of the top card in a deck, decrements the top and
	             returns the copy
        Preconditions:  theDeck is created, top is declared
        Postconditions:  The top is decrememnted and the deleted card is returned
        */
	Card pop();
};

/*
Class: 		EuchreDeck32
Description:	This class represents a 32 card deck in a card game. Its a derived class
                from DeckType. 
*/

class EuchreDeck32 : public DeckType {
public:
        /*
        Name: EuchreDeck32()
        Description: Default Constructor
        Preconditions:  variables are declared
        Postconditions:  The decks are initialized and inserted
        */
	EuchreDeck32();
	
	/*
        Name: shuffle()
        Description: Shuffles the cards in deck 
        Preconditions:  variables are declared
        Postconditions:  The cards in a deck are shuffled randomly.
        */
	void shuffle();
	
	/*
        Name: isEmpty() const
        Description: Checks if the deck is empty or not
        Preconditions:  top is declared
        Postconditions:  Returns true if the deck is empty, otherwise returns
	                 false
        */
	bool isEmpty() const;
	
	/*
        Name: pop()
        Description: Gets a copy of the top card in a deck, decrements the top and
	             returns the copy
        Preconditions:  theDeck is created, top is declared
        Postconditions:  The top is decrememnted and the deleted card is returned
        */
	Card pop();
};
#endif

