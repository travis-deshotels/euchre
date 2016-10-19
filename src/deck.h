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

