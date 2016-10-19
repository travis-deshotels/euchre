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
