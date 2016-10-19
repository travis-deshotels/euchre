#include "hand.h"
#include "gamemanager.h"
#include "trick.h"
#include "handiterator.h"
using namespace std;

Trick::Trick(GameManager *GM) {
   _GameManager = GM;
   layoutCards = new Hand(4); 
}

Trick::Trick(){

}

Trick::~Trick() {
   delete layoutCards;
}

bool Trick::isEmpty() {
	return layoutCards->isEmpty();
}

void Trick::addPlayedCard(Card playedCard) {
     //if(layoutCards->getNumCards() >= 4) {
        //_GameManager->getTrick(layoutCards);
     //}
     //else {
        layoutCards->add(playedCard);
     //}
}
/*
Hand* Trick::returnCardsPlayed() {
     return layoutCards;
}
*/
HandIterator Trick::createIterator() {
	return( *( new HandIterator(layoutCards) ) );
}
