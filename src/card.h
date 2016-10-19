/* 
   header file for class Card
   filename: card.h
*/
#ifndef CARD_H
#define CARD_H

/*
Class: 		Card
Description:	This class represents a card in a card in a card game.
   It contains a suit, rank , and a value associated with a card.
*/

class Card {
public:
        /*
        Name: Card()
        Description: Default Constructor
        Preconditions:  none
        Postconditions:  A Card object is created.
        */
	Card();
	
        /*
        Name: Card( char _rank, char _suit, int _value);
        Description: Constructor
        Preconditions:  There is a suit, value, and rank to create a card with.
        Postconditions:  A Card object is created with rank = _rank, suit =
	   _suit, and value = _value.
        */
	Card( char _rank, char _suit, int _value);
	
        /*
        Name: getRank() const
        Description: This function returns the rank of this card.
        Preconditions:  There is a Card object.
        Postconditions:  The rank of this card object is returned.
        */	
	char getRank() const;
	
        /*
        Name: getSuit() const
        Description: This function returns the suit of this card.
        Preconditions:  There is a Card object.
        Postconditions:  The suit of this card object is returned.
        */
	char getSuit() const;
	
        /*
        Name: getValue() const
        Description: This function returns the value of this card.
        Preconditions:  There is a Card object.
        Postconditions:  The value of this card object is returned.
        */	
	int getValue() const;
	
        /*
        Name: operator == ( Card ) const
        Description: overloaded equals operator.
        Preconditions:  There is a Card to compare this card to.
        Postconditions:  returns true if the rank,suit and cvalue are the same.
	   Else this function returns false.
        */	
	bool operator == ( Card ) const;

        /*
        Name: operator = ( Card )
        Description: overloaded assignment operator.
        Preconditions:  There is a Card to compare this card to.
        Postconditions:  assigns the value, rank, and suit if the card passes to
	  this card.
        */		
	void operator = ( Card );
	
        /*
        Name: operator > ( Card ) const
        Description: overloaded > operator to compare cards
        Preconditions:  There is a card to compare this card to.
        Postconditions:  Returns true if this cards value is greater than the
	passed card. else this function returns false.
        */	
	bool operator > ( Card ) const;
	
        /*
        Name: setRank( char _rank)
        Description: Sets this Card's rank to _rank that is passed.
        Preconditions:  There is a card object.
        Postconditions:  The rank of this card is set to _rank
        */	
	void setRank( char );
	
        /*
        Name: setSuit( char _rank)
        Description: Sets this Card's suit to _suit that is passed.
        Preconditions:  There is a card object.
        Postconditions:  The suit of this card is set to _suit
        */	
	void setSuit( char );

        /*
        Name: setValue( char _value)
        Description: Sets this Card's value to _value that is passed.
        Preconditions:  There is a card object.
        Postconditions:  The value of this card is set to _value
        */	
	void setValue( int );
	
private:
	struct aCard {
		/*Name: rank
                Description: stores the rank of a card.
		*/
		char rank;
   		
		/*
        	Name: suit
        	Description: stores the suit of a card.
        	*/
		char suit;
	        
		/*
                Name: value
                Description: stores the value of a card.
                */	
		int value;
	};
   	aCard card;
};
#endif
