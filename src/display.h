#ifndef DISPLAY_H
#define DISPLAY_H
#include "card.h"
#include "handtype.h"
#include "gamemanager.h"
#include <fstream>
#include <string>

using namespace std;

/*
Class: 		DisplayType
Description:	This class represents different display messages for the game
                euchre. It is a root class.
*/

class DisplayType {
public:
        /*
        virtual functions
        */
	virtual void setHands() =0;
	virtual void endl() =0;
	virtual char getFirstChoice() =0;
	virtual void welcomeMsg() =0;

	virtual void helpScreen() =0;
	virtual void goBack() =0;
	
	virtual void flipCard() =0;
	virtual void callTrump() =0;
	virtual char callChoice() =0;
	virtual void pickTrump() =0;
	
	virtual void askForMove() =0;
	virtual void yourHand() =0;
	virtual int getMove() =0;
	
	virtual void invalidChoice() =0;
		
	virtual void displayHand( int ) =0;
	virtual void displayTrick() =0;
	
	virtual void continueMsg() =0;
	virtual char getContinue() =0;
	
	virtual void displayCard( Card ) =0;
	
	virtual void displayScore( int ) =0;
	virtual void displayPlayerNumber( int ) =0;
	virtual void displayBid() =0;
	virtual void displayDealerDiscard() =0;
	virtual void displayTrump( char ) =0;
	virtual void displayAlone() =0;
	virtual void displayTrickWinner( int ) =0;
	virtual void displayHandIs() =0;
	virtual void displayTrickIs() =0;

};
/*
Class: 		Display
Description:	This class represents different display messages for the game
                euchre. It is a derived class from DisplayType.
*/
class Display : public DisplayType {
public:
        /*
        Name: Display( )
        Description: Constructor
        Preconditions:  none
        Postconditions:  none
        */
	Display( GameManager* );
	
	/*
        Name: setHand();
        Description: Sets the hand pointer in this class.
        Preconditions:  There is a pointer to some hand.
        Postconditions:  The pointer in this class is set.
        */
	void setHands();
	
	/*
        Name: endl( )
        Description: Prints out a new line
        Preconditions:  none
        Postconditions:  a new line has been printed out to screen
        */
	void endl();
	
	/*
        Name: getFirstChoice( )
        Description: Prompts the user to enter a choice which is a character and
	             returns the value to the function
        Preconditions:  none
        Postconditions:  The user's input is returned.
        */
	char getFirstChoice();
	
	/*
        Name: welcomeMsg( )
        Description: Displays a welcome message to the user
        Preconditions:  none
        Postconditions:  The welcome message is displayed to the user
        */
	void welcomeMsg();
	
	/*
        Name: helpScreen( )
        Description: Displays the help message after user chooses the help 
	             option in the menu.
        Preconditions:  none
        Postconditions:  Help message is displayed to the user
        */
	void helpScreen();
	
	/*
        Name: goBack( )
        Description: prompts the user to enter a key and just puts that char
	             into a junk variable
        Preconditions:  none
        Postconditions:  User's input is put into junk variable
        */
	void goBack();
	
	/*
        Name: flipCard( )
        Description: DIsplays the flipped card message
        Preconditions:  none
        Postconditions:  The flipped card message is displayed
        */
	void flipCard();
	
	/*
        Name: callTrump( )
        Description: Displays a message asking user to play the current trump
        Preconditions:  none
        Postconditions:  Trump message is displayed
        */
	void callTrump();
	
	/*
        Name: callChoice( )
        Description: Prompts the user to enter a choice and returns it
        Preconditions:  none
        Postconditions:  Gets the user choice and returns it.
        */
	char callChoice();
	
	/*
        Name: pickTrump( )
        Description: Displays a message to choose a trump
        Preconditions:  none
        Postconditions:  The trump message is displayed
        */
	void pickTrump();
	
        /*
        Name: askForMove( )
        Description: Displays a message to choose a card
        Preconditions:  none
        Postconditions:  Card choice message is displayed
        */
	void askForMove();
	
	/*
        Name: yourHand( )
        Description: Displays a user's hand message
        Preconditions:  none
        Postconditions:  Hand message is displayed
        */
	void yourHand();
	
	/*
        Name: getMove( )
        Description: Prompts the user to enter a choice and returns it
        Preconditions:  none
        Postconditions:  User's choice is returned
        */
	int getMove();
	
	/*
        Name: invalidChoice( )
        Description: Displays invalid choice message
        Preconditions:  none
        Postconditions:  Invalid choice message is displayed
        */
	void invalidChoice();
	
	/*
        Name: displayHand( )
        Description: Displays the cards in user's hand
        Preconditions:  none
        Postconditions:  Cards in user's hand is displayed
        */
	void displayHand( int );
	
	/*
        Name: displayTrick();( )
        Description: Shows the cards in the current trick.
        Preconditions:  There is a trick object
        Postconditions:  The contents of the trick are displayed.
        */
	void displayTrick();
	
	/*
        Name: continueMsg( )
        Description: Asks the user to play again or not
        Preconditions:  none
        Postconditions:  Continue message is displayed
        */
	void continueMsg();
	
	/*
        Name: getContinue( )
        Description: Gets the user choice and returns it
        Preconditions:  none
        Postconditions:  User's choice is returned
        */
	char getContinue();
	
	/*
        Name: displayCard( Card )
        Description: Receives 1 parameter of type Card and displays the card rank and suit
        Preconditions:  Card is initialized
        Postconditions:  The card's rank and suit is displayed
        */
	void displayCard( Card );
	
	/*
        Name: displayScore( int )
        Description: Receives 1 parameter of type int and displays 
	             the user's score
        Preconditions:  none
        Postconditions:  The user's score is displayed
        */
	void displayScore( int );
	
	/*
        Name: displayPlayerNumber( int );
        Description: Displays the current player.
        Preconditions:  There is an integer for the current player.
        Postconditions:  The current player is shown on the screen.
        */
	void displayPlayerNumber( int );
	
	/*
        Name: displayBid();
        Description: Asks the user what the user wants to bid on the screen 
        Preconditions:  none
        Postconditions:  menu with choices displayed on the screen.
        */
	void displayBid();
	
	/*
        Name: displayDealerDiscard()
        Description: shows the string "Dealer: please choose a card to discard\n"
        Preconditions:  none
        Postconditions:  the string is displyed on the screen.
        */
	void displayDealerDiscard();
	
	/*
        Name: displayTrump( char );
        Description: Shows the trump suit on the screen.
        Preconditions:  There is a trump suit represented by a char.
        Postconditions:  The suit is outputed onto the screen.
        */
	void displayTrump( char );
	
	/*
        Name: displayAlone()
        Description: displays "Would you like to play alone?(y/n)\n" on the screen
        Preconditions:  none
        Postconditions:  the string is displayed on the screen
        */
	void displayAlone();
	
	/*
        Name: displayTrickWinner( int );
        Description: Shows the trick winner on the screen.
        Preconditions:  There is an integer index of the winning player
        Postconditions:  The trick winning player is displayed on the screen
        */
	void displayTrickWinner( int );
	
	/*
        Name: displayHandIs();
        Description: shows the string  "Your hand is:\n"
        Preconditions:  none
        Postconditions:  the string is oupted to the screen
        */
	void displayHandIs();
	
	/*
        Name: displayTrickIs()
        Description: shows the string "Cards currently in trick:\n"
        Preconditions:  none
        Postconditions:  string is outputed to the screen.
        */
	void displayTrickIs();
private:
	/*
        Name: gm 
        Description: pointer to the gamemanager of the game. 
        */
	GameManager* gm;
	
	/*
        Name: hands
        Description: pointers to the hands in the current game.
        */
	Hand* hands;
};

#endif
