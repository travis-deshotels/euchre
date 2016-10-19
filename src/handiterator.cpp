#include "handiterator.h"

HandIterator::HandIterator( Hand* hand ) {
	theHand = hand;
}

void HandIterator::begin() {
	iter = theHand->hand.begin();
}

int HandIterator::end() {
	return( iter == theHand->hand.end() );
}

Card HandIterator::operator*() {
	return *iter;
}

void HandIterator::operator++( int ) {
	iter++;
} 
