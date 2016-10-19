#ifndef FACTORY_H
#define FACTORY_H
#include "deck.h"

/*
Class: 	Factory
Description:	This class is a bse abstract class for the deck factories
*/
class Factory{
public:
	virtual DeckType* createDeck();
};

/*
Class: 		EuchreFactory
Description:	This class creates a standard deck of euchre cards
*/
class EuchreFactory: public Factory{
public:
	DeckType* createDeck();
};

/*
Class: 		Euchre32Facory
Description:	This class creates a deck of 32 cards for the euchre game.
*/
class Euchre32Factory: public Factory{
public:
	DeckType* createDeck();
};
#endif
