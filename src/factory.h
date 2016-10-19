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
