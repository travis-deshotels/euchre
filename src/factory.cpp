#include "factory.h"

DeckType* EuchreFactory::createDeck() {
	return( new EuchreDeck() );
}

DeckType* Euchre32Factory::createDeck() {
	return( new EuchreDeck32() );
}
