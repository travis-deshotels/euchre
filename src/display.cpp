/*
    implementation file for class Display
    filename: display.cpp
*/
#include "handiterator.h"
#include "display.h"
#include "trick.h"
#include <iostream>

Display::Display( GameManager* mgr ) {
        /*
        Name: Display( )
        Description: Constructor
        Preconditions:  none
        Postconditions:  none
        */
	gm = mgr;
}

void Display::setHands() {
	hands = gm->getCardsFromHand();
}

void Display::endl() {
        /*
        Name: endl( )
        Description: Prints out a new line
        Preconditions:  none
        Postconditions:  a new line has been printed out to screen
        */
	cout<<" \n";
}

char Display::getFirstChoice() { 
        /*
        Name: getFirstChoice( )
        Description: Prompts the user to enter a choice which is a character and
	             returns the value to the function
        Preconditions:  none
        Postconditions:  The user's input is returned.
        */
	char temp;
	cin>>temp;
	return temp;
}

void Display::welcomeMsg() {
        /*
        Name: welcomeMsg( )
        Description: Displays a welcome message to the user
        Preconditions:  none
        Postconditions:  The welcome message is displayed to the user
        */
	cout<<"Welcome to the game\n\n";
	cout<<"Type 'b' to begin\n";
	cout<<"Type 'h' if you need help\n: ";
}

void Display::helpScreen() {
        /*
        Name: helpScreen( )
        Description: Displays the help message after user chooses the help 
	             option in the menu.
        Preconditions:  none
        Postconditions:  Help message is displayed to the user
        */
	ifstream inFile;
	string data;
	inFile.open("help.txt");
	if(!inFile)
		cout<<"Could not open";
	else{
	getline(inFile, data);
	cout<<data;
	
	while(!inFile.eof()) {
		getline(inFile, data);
		cout<<data;
	}
	cout<<"\n"<<"\n";
	cout<<"Enter any character to continue: ";}
}

void Display::goBack() {
        /*
        Name: goBack( )
        Description: prompts the user to enter a key and just puts that char
	             into a junk variable
        Preconditions:  none
        Postconditions:  User's input is put into junk variable
        */
	char junk;
	cin>>junk;
}

void Display::flipCard() {
        /*
        Name: flipCard( )
        Description: DIsplays the flipped card message
        Preconditions:  none
        Postconditions:  The flipped card message is displayed
        */
	cout<<"This is the flipped card: ";
}

void Display::callTrump() {
        /*
        Name: callTrump( )
        Description: Displays a message asking user to play the current trump
        Preconditions:  none
        Postconditions:  Trump message is displayed
        */
	cout<<"Would you like to play with this trump? y/n \n";
	cout<<": ";
}
char Display::callChoice() {
        /*
        Name: callChoice( )
        Description: Prompts the user to enter a choice and returns it
        Preconditions:  none
        Postconditions:  Gets the user choice and returns it.
        */
	char choice;
	cin>>choice;
	return choice;
}

void Display::pickTrump() {
        /*
        Name: pickTrump( )
        Description: Displays a message to choose a trump
        Preconditions:  none
        Postconditions:  The trump message is displayed
        */
	cout<<"Enter a suit if you wish to choose trump (c,d,h,s)\n";
	cout<<"Or enter x to pass\n";
}

void Display::askForMove() {
        /*
        Name: askForMove( )
        Description: Displays a message to choose a card
        Preconditions:  none
        Postconditions:  Card choice message is displayed
        */
	cout<<"Please choose a card to play\n";
}

void Display::yourHand() {
        /*
        Name: yourHand( )
        Description: Displays a user's hand message
        Preconditions:  none
        Postconditions:  Hand message is displayed
        */
	cout<<"Your hand is: \n";
}

int Display::getMove() {
        /*
        Name: getMove( )
        Description: Prompts the user to enter a choice and returns it
        Preconditions:  none
        Postconditions:  User's choice is returned
        */
	int choice;
	cin>>choice;
	return choice;
}

void Display::invalidChoice() {
        /*
        Name: invalidChoice( )
        Description: Displays invalid choice message
        Preconditions:  none
        Postconditions:  Invalid choice message is displayed
        */
	cout<<"You must follow suit:\n";
}
	
void Display::displayHand( int index ) {
        /*
        Name: displayHand( )
        Description: Displays the cards in user's hand
        Preconditions:  none
        Postconditions:  Cards in user's hand is displayed
        */
	HandIterator iter  = hands[index].createIterator();
	
	iter.begin();
		
	while( !iter.end() ) {
		displayCard( *iter );
		cout<<' ';
		iter++;
	}
	cout<<"\n";
	
}

void Display::displayTrick() {
	HandIterator iter = gm->getTrick()->createIterator();
	
	iter.begin();
	if( iter.end() )
		cout<<"None";
	while( !iter.end() ) {
		displayCard(*iter);
		cout<<' ';
		iter++;
	}

}

void Display::continueMsg() {
        /*
        Name: continueMsg( )
        Description: Asks the user to play again or not
        Preconditions:  none
        Postconditions:  Continue message is displayed
        */
	cout<<"Would you like to play again? y/n\n";
	cout<<": ";
}

char Display::getContinue() {
        /*
        Name: getContinue( )
        Description: Gets the user choice and returns it
        Preconditions:  none
        Postconditions:  User's choice is returned
        */
	char choice;
	cin>>choice;
	return choice;
}

void Display::displayCard( Card theCard ) {	
        /*
        Name: displayCard( Card )
        Description: Receives 1 parameter of type Card and displays the card rank and suit
        Preconditions:  Card is initialized
        Postconditions:  The card's rank and suit is displayed
        */
	cout<<theCard.getRank()<<theCard.getSuit()<<' ';
}

void Display::displayScore( int x ) {
        /*
        Name: displayScore( int )
        Description: Receives 1 parameter of type int and displays 
	             the user's score
        Preconditions:  none
        Postconditions:  The user's score is displayed
        */
	cout<<"Your score is ";
	cout<<x<<"\n";
}

void Display::displayPlayerNumber( int x ) {
	cout<<"Player"<<x;
}

void Display::displayBid() {
	cout<<"Would you to play\n";
	cout<<"Enter 0 to pass\n";
	cout<<"Enter 3 to play\n";
	cout<<"Enter 5 to play alone\n";
}

void Display::displayDealerDiscard() {
	cout<<"Dealer: please choose a card to discard\n";
}

void Display::displayAlone() {
	cout<<"Would you like to play alone?(y/n)\n";
}

void Display::displayTrickWinner( int winner ) {
	cout<<"player "<<winner<<" won the Trick\n";
}

void Display::displayTrump( char trump ) {
	cout<<"The trump is "<<trump<<"\n";
}

void Display::displayHandIs() {
	cout<<"Your hand is:\n";
}

void Display::displayTrickIs() {
	cout<<"Cards currently in trick:\n";
}
