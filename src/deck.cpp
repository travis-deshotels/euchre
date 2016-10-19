#include "deck.h"
#include <time.h>
/*****************************************************************************
	This is the 24 card euchre deck
*****************************************************************************/
EuchreDeck::EuchreDeck() {
        /*
        Name: EuchreDeck()
        Description: Default Constructor
        Preconditions:  variables are declared
        Postconditions:  The decks are initialized and inserted
        */
	theDeck = new Card[ 24 ];
	time_t t;
	srand((unsigned) time(&t)); 
	int i;
	char ranks[] = { '9', 'T', 'J', 'Q', 'K', 'A' };
	int values[] = { 9, 10, 11, 12, 13, 14 };

	int j=0;
	for( i=0;i<6;i++ ) {
		theDeck[ i ].setRank( ranks[ j ] );
		theDeck[ i ].setSuit( 'c' );
		theDeck[ i ].setValue( values[ j ] );
		j++;
	}
	j=0;
	for( i=6;i<12;i++ ) {
		theDeck[ i ].setRank( ranks[ j ] );
		theDeck[ i ].setSuit( 'd' );
		theDeck[ i ].setValue( values[ j ] );
		j++;
	}
	j=0;
	for( i=12;i<18;i++ ) {
		theDeck[ i ].setRank( ranks[ j ] );
		theDeck[ i ].setSuit( 'h' );
		theDeck[ i ].setValue( values[ j ] );
		j++;
	}
	j=0;
	for( i=18;i<24;i++ ) {
		theDeck[ i ].setRank( ranks[ j ] );
		theDeck[ i ].setSuit( 's' );
		theDeck[ i ].setValue( values[ j ] );
		j++;
	}
	top = 23;

}

void EuchreDeck::shuffle() {
        /*
        Name: shuffle()
        Description: Shuffles the cards in deck 
        Preconditions:  variables are declared
        Postconditions:  The cards in a deck are shuffled randomly.
        */
	top = 23;	
	int x;
	Card* temp;
	for( int i=0;i<22;i++ ) {
		x = rand() % top;
		temp = new Card( theDeck[top].getRank(), theDeck[top].getSuit(), theDeck[top].getValue() );
		theDeck[ top-- ] = theDeck[ x ];
		theDeck[ x ].setRank( temp->getRank() );
		theDeck[ x ].setSuit( temp->getSuit() );
		theDeck[ x ].setValue( temp->getValue() );
		delete temp;
	}
	top = 23;
}

Card EuchreDeck::pop() {
        /*
        Name: pop()
        Description: Gets a copy of the top card in a deck, decrements the top and
	             returns the copy
        Preconditions:  theDeck is created, top is declared
        Postconditions:  The top is decrememnted and the deleted card is returned
        */
	return( theDeck[ top-- ] );
}

bool EuchreDeck::isEmpty() const {
        /*
        Name: isEmpty() const
        Description: Checks if the deck is empty or not
        Preconditions:  top is declared
        Postconditions:  Returns true if the deck is empty, otherwise returns
	                 false
        */
	return( top == -1 );
}

/*****************************************************************************
	This is the 32 card euchre deck
*****************************************************************************/

EuchreDeck32::EuchreDeck32() {
        /*
                Class: 		EuchreDeck32
                Description:	This class represents a 32 card deck in a card game. Its a derived class
                from DeckType. 
        */
	theDeck = new Card[ 32 ];
	time_t t;
	srand((unsigned) time(&t)); 
	int i;
	char ranks[] = { '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };
	int values[] = { 7, 8, 9, 10, 11, 12, 13, 14 };

	int j=0;
	for( i=0;i<8;i++ ) {
		theDeck[ i ].setRank( ranks[ j ] );
		theDeck[ i ].setSuit( 'c' );
		theDeck[ i ].setValue( values[ j ] );
		j++;
	}
	j=0;
	for( i=8;i<16;i++ ) {
		theDeck[ i ].setRank( ranks[ j ] );
		theDeck[ i ].setSuit( 'd' );
		theDeck[ i ].setValue( values[ j ] );
		j++;
	}
	j=0;
	for( i=16;i<24;i++ ) {
		theDeck[ i ].setRank( ranks[ j ] );
		theDeck[ i ].setSuit( 'h' );
		theDeck[ i ].setValue( values[ j ] );
		j++;
	}
	j=0;
	for( i=24;i<32;i++ ) {
		theDeck[ i ].setRank( ranks[ j ] );
		theDeck[ i ].setSuit( 's' );
		theDeck[ i ].setValue( values[ j ] );
		j++;
	}
	top = 31;
}

void EuchreDeck32::shuffle() {
        /*
        Name: shuffle()
        Description: Shuffles the cards in deck 
        Preconditions:  variables are declared
        Postconditions:  The cards in a deck are shuffled randomly.
        */
	top = 31;	
	int x;
	Card* temp;
	for( int i=0;i<30;i++ ) {
		x = rand() % top;
		temp = new Card( theDeck[top].getRank(), theDeck[top].getSuit(), theDeck[top].getValue() );
		theDeck[ top-- ] = theDeck[ x ];
		theDeck[ x ].setRank( temp->getRank() );
		theDeck[ x ].setSuit( temp->getSuit() );
		theDeck[ x ].setValue( temp->getValue() );
		delete temp;
	}
	top = 31;

}

bool EuchreDeck32::isEmpty() const{
        /*
        Name: isEmpty() const
        Description: Checks if the deck is empty or not
        Preconditions:  top is declared
        Postconditions:  Returns true if the deck is empty, otherwise returns
	                 false
        */
	return( top == -1 );
}

Card EuchreDeck32::pop(){
        /*
        Name: pop()
        Description: Gets a copy of the top card in a deck, decrements the top and
	             returns the copy
        Preconditions:  theDeck is created, top is declared
        Postconditions:  The top is decrememnted and the deleted card is returned
        */
	return( theDeck[ top-- ] );
}
/*****************************************************************************
	This is a standard 52 card deck, not used in this project
*****************************************************************************/
Deck::Deck() {
        /*
        Name: Deck()
        Description: Default Constructor
        Preconditions:  variables are declared
        Postconditions:  The decks are initialized and inserted
        */
	theDeck = new Card[ 52 ];
	time_t t;
	srand((unsigned) time(&t)); 
	int i;
	char ranks[] = { '2', '3', '4', '5', '6', '7', '8',\
   	'9', 'T', 'J', 'Q', 'K', 'A' };
	int values[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, -10, -10, -10, 1 };

	int j=0;
	for( i=0;i<13;i++ ) {
		theDeck[ i ].setRank( ranks[ j ] );
		theDeck[ i ].setSuit( 'c' );
		theDeck[ i ].setValue( values[ j ] );
		j++;
	}
	j=0;
	for( i=13;i<26;i++ ) {
		theDeck[ i ].setRank( ranks[ j ] );
		theDeck[ i ].setSuit( 'd' );
		theDeck[ i ].setValue( values[ j ] );
		j++;
	}
	j=0;
	for( i=26;i<39;i++ ) {
		theDeck[ i ].setRank( ranks[ j ] );
		theDeck[ i ].setSuit( 'h' );
		theDeck[ i ].setValue( values[ j ] );
		j++;
	}
	j=0;
	for( i=39;i<52;i++ ) {
		theDeck[ i ].setRank( ranks[ j ] );
		theDeck[ i ].setSuit( 's' );
		theDeck[ i ].setValue( values[ j ] );
		j++;
	}
	top = 51;
}
void Deck::shuffle() {
        /*
        Name: shuffle()
        Description: Shuffles the cards in deck 
        Preconditions:  variables are declared
        Postconditions:  The cards in a deck are shuffled randomly.
        */
	top = 51;	
	int x;
	Card* temp;
	for( int i=0;i<50;i++ ) {
		x = rand() % top;
		temp = new Card( theDeck[top].getRank(), theDeck[top].getSuit(), theDeck[top].getValue() );
		theDeck[ top-- ] = theDeck[ x ];
		theDeck[ x ].setRank( temp->getRank() );
		theDeck[ x ].setSuit( temp->getSuit() );
		theDeck[ x ].setValue( temp->getValue() );
		delete temp;
	}
	top = 51;
}

Card Deck::pop() {
        /*
        Name: pop()
        Description: Gets a copy of the top card in a deck, decrements the top and
	             returns the copy
        Preconditions:  theDeck is created, top is declared
        Postconditions:  The top is decrememnted and the deleted card is returned
        */
	return( theDeck[ top-- ] );
}

bool Deck::isEmpty() const {
         /*
        Name: isEmpty() const
        Description: Checks if the deck is empty or not
        Preconditions:  top is declared
        Postconditions:  Returns true if the deck is empty, otherwise returns
	                 false
        */
	 return( top == -1 );
}
