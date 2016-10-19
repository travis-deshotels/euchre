/*
   implementation file for class Card
   filename: card.cpp
*/
#include "card.h"

Card::Card(){
        /*
        Name: Card
        Description: Default Constructor
        Preconditions:  none
        Postconditions:  A Card object is created.
        */
}

Card::Card( char _rank, char _suit, int _value ) {
        /*
        Name: Card( char _rank, char _suit, int _value);
        Description: Constructor
        Preconditions:  There is a suit, value, and rank to create a card with.
        Postconditions:  A Card object is created with rank = _rank, suit =
	   _suit, and value = _value.
        */
	card.rank = _rank;
	card.suit = _suit;
	card.value = _value;
}

char Card::getRank() const {
        /*
        Name: getRank() const
        Description: This function returns the rank of this card.
        Preconditions:  There is a Card object.
        Postconditions:  The rank of this card object is returned.
        */
	return card.rank;
}

char Card::getSuit() const {
        /*
        Name: getSuit() const
        Description: This function returns the suit of this card.
        Preconditions:  There is a Card object.
        Postconditions:  The suit of this card object is returned.
        */
	return card.suit;
}

int Card::getValue() const {
        /*
        Name: getValue() const
        Description: This function returns the value of this card.
        Preconditions:  There is a Card object.
        Postconditions:  The value of this card object is returned.
        */
	return card.value;
}

bool Card::operator == ( Card C ) const {
        /*
        Name: operator == ( Card ) const
        Description: overloaded equals operator.
        Preconditions:  There is a Card to compare this card to.
        Postconditions:  returns true if the rank,suit and cvalue are the same.
	   Else this function returns false.
        */
	if( card.rank == C.getRank() )
		if( card.suit == C.getSuit() )
				return true;
	return false;
}

void Card::operator = ( Card C ) {
        /*
        Name: operator = ( Card )
        Description: overloaded assignment operator.
        Preconditions:  There is a Card to compare this card to.
        Postconditions:  assigns the value, rank, and suit if the card passes to
	  this card.
        */
	card.rank = C.getRank();
	card.suit = C.getSuit();
	card.value = C.getValue();
}

bool Card::operator > ( Card C ) const {
        /*
        Name: operator > ( Card ) const
        Description: overloaded > operator to compare cards
        Preconditions:  There is a card to compare this card to.
        Postconditions:  Returns true if this cards value is greater than the
	passed card. else this function returns false.
        */
	return ( card.value > C.getValue() );
}

void Card::setRank( char _rank ) {
        /*
        Name: setRank( char _rank)
        Description: Sets this Card's rank to _rank that is passed.
        Preconditions:  There is a card object.
        Postconditions:  The rank of this card is set to _rank
        */
	card.rank = _rank;
}

void Card::setSuit( char _suit ) {
        /*
        Name: setSuit( char _rank)
        Description: Sets this Card's suit to _suit that is passed.
        Preconditions:  There is a card object.
        Postconditions:  The suit of this card is set to _suit
        */
 	card.suit = _suit;
}

void Card::setValue( int _value ) {
        /*
        Name: setValue( char _value)
        Description: Sets this Card's value to _value that is passed.
        Preconditions:  There is a card object.
        Postconditions:  The value of this card is set to _value
        */
	card.value = _value;
}
