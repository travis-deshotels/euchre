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

#ifndef HAND_H
#define HAND_H

#include "handtype.h"
#include <list>

/*
Class: 		Hand
Description:	The Hand class stores all of the cards in a players hand.
*/

class Hand : public HandType {
   public:
      friend class HandIterator;
      friend class TrickIterator;
      /*
      Name: Hand()
      Description: Default constructor
      Preconditions:  none
      Postconditions:  A hand object is created with maxHandSize = 5
      */
      Hand();
      
      /*
      Name: Hand(int HANDSIZE)
      Description: constructor
      Preconditions:  The max number of cards in a hand needs to be passed
      Postconditions:  A hand object is created with maxHandSize = HANDSIZE
      */
      Hand(int HANDSIZE);
      
      /*
      Name: add(Card DRAW)
      Description: This function adds a card to this hand object.
      Preconditions:  A card DRAW is to be added to this hand object.
      Postconditions:  A card DRAW is added to the list in this hand.
      */
      void add(Card DRAW);
      
      /*
      Name: remove(Card removedCard)
      Description: This function removes a card from this hand object.
      Preconditions:  A card removeCard is to be removed from this hand object.
      Postconditions:  A card DRAW is deleted from the list in this hand.
      */
      Card remove(Card removedCard);
      
      /*
      Name: isEmpty()
      Description: This function returns if the card list is empty.
      Preconditions:  A hand object is instantiated.
      Postconditions:  Returns true if the card list is 0, otherwise it returns
         false.
      */
      bool isEmpty();
      
      /*
      Name: getNumCards()
      Description: This function returns the number of cards in the card list.
      Preconditions:  A hand object is instantiated.
      Postconditions:  Returns the number of elements in the card list in this 
         hand.
      */
      int getNumCards();
      
      /*
      Name: returnCardList()
      Description: This function returns the list of cards in this hand
      Preconditions:  A hand object is instantiated.
      Postconditions:  Returns the cardlist.
      */
      HandIterator createIterator();
      
  private:
      /*
      Name: hand
      Description: This is the list of cards in this Hand.
      */
      list<Card> hand;
};

#endif
