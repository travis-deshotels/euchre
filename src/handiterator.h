#ifndef HANDITERATOR_H
#define HANDITERATOR_H
#include "handiteratortype.h"
#include "hand.h"

/*
Class: 		HandIterator
Description:	This class defines an iterator for the hand class.
*/
class HandIterator : public HandIteratorType {
   public:
      /*
        Name: DeckType()
        Description: Default Constructor
        Preconditions:  none
        Postconditions:  none
      */
      HandIterator( Hand* );
      
      /*
        Name: begin
        Description: sets the iterator to the beginning of the list
        Preconditions:  there is an iterator
        Postconditions:  the iterator is set to the beginning of the list
      */
      void begin();
      
      /*
        Name: end
        Description: returns whether the end of the hand is returned
        Preconditions:  there is an iterator
        Postconditions:  1 is returned if the iterator points to the last 
            item in the list, 0 otherwise.
      */
      int end();
      
      /*
        Name: 
        Description: operator*
        Preconditions:  there is an iterator object
        Postconditions:  the object that the iterator points to is returned
      */
      Card operator*();
      
      /*
        Name: operator++
        Description: incremention operator
        Preconditions:  there is an iterator
        Postconditions:  the iterator points to the next item in the list
      */
      void operator++( int );
   private:
      /*
        Name: iter
        Description: Iterator for a list 
      */
      list<Card>::iterator iter;
  
      /*
        Name: theHand
        Description: pointer to the hand being iteratorated
      */
      Hand* theHand;
};
#endif
