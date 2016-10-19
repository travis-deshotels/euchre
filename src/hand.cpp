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
