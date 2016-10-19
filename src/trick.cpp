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
