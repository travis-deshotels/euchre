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
 
#ifndef HANDTYPE_H
#define HANDTYPE_H

#include "card.h"
class HandType;
#include "handiteratortype.h"

using namespace std;

/*
Class: 		HandType
Description:	An abstract base class of Hand
*/

class HandType {
   public:
      // base class virtual functions.
      virtual void add(Card DRAW) = 0;
      virtual Card remove(Card removedCard) = 0;
      virtual bool isEmpty() = 0;
      virtual int getNumCards() = 0;
   protected:
      /*
      Name: maxHandSize
      Description: The maximum number of cards that can be in a hand.
      */
     int maxHandSize;
};
#endif
