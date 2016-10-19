#ifndef HANDITERATORTYPE_H
#define HANDITERATORTYPE_H
#include "handtype.h"

using namespace std;

/*
Class:		HandIteratorType
Description:	This is the base class for hand iterators
*/
class HandIteratorType {
   public:
      // base class virtual functions
      virtual void begin() = 0;
      virtual int end() = 0;
      virtual Card operator*() = 0;
      virtual void operator++( int ) = 0;
};
#endif
