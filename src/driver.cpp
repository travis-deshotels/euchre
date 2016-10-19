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

#include "display.h"
#include "deck.h"
#include "gamemanager.h"
#include "handtype.h"
#include "score.h"

using namespace std;

void welcome( Display );

int main() {
	GameManager gm;
	Display myDisplay(&gm);
	bool trump;
	int dealer = 0, leader, points;
	
	// startscreen
	welcome( myDisplay );
	
	// while game is not won
	while(!gm.isWon()) {
	   dealer = dealer % 4;
	   leader = (dealer + 1) % 4;
	//   deal hands
	   gm.resetHands();
	   gm.setDealer(dealer);
	   gm.dealHands();
	//   ask players to pick up, lone, or pass
	   trump = gm.makeBids();
	//   if there is no pick up
	   if(!trump)  {
	//        pick another trump
	      trump = gm.pickTrump();
	//        if no picked trump
	   }  
	//            deal again
	// if there is a trump
	  if(trump) {
	   //   for 5 tricks
	   for(int i=0; i<5; i++) { 
	   //       playcards into tricks
	      leader = gm.playRound(leader);
	   }
	
	   //   total the number of tricks for the teams
	   points = gm.calcPoints();
	   //   find out which team won the round and increment the score, and loop back to the while
	   gm.setPoints(points);
	   myDisplay.displayScore(gm.getScore(0));
	   myDisplay.displayScore(gm.getScore(1));
	  }
	  //*/
	  dealer++;
	}
}

void welcome( Display D ) {
	char choice;
	
	D.welcomeMsg();
	choice = D.getFirstChoice();
	if( choice == 'h' ) {
		D.helpScreen();
		D.goBack();
	}
}
