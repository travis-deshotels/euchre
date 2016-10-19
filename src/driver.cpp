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
