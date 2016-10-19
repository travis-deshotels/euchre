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

#include "hand.h"
#include "card.h"
#include "handiterator.h"

using namespace std;

Hand::Hand() {
	maxHandSize = 5;
}

Hand::Hand(int HANDSIZE) {
   maxHandSize = HANDSIZE;
}

void Hand::add(Card addedCard) {
   //if(hand.size() >= maxHandSize) {
      //cout << "Error: Hand is full, cannot add card." << endl;
      //cout << "Max Hand Size is: " << maxHandSize <<endl;
      //}
   //else
      hand.push_back(addedCard);
}

Card Hand::remove(Card removedCard) {
   //if(hand.empty())
      //cout << "Error: Empty hand, cannot remove card." << endl;
   //else
      hand.remove(removedCard);
   return removedCard;  
}

int Hand::getNumCards() {
   return hand.size();
}

bool Hand::isEmpty() {
   return hand.empty();
}

HandIterator Hand::createIterator() {
	return( *new HandIterator(this) );
}
