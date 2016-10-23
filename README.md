# euchre
An old project from my software engineering class.

Euchre is a "trick-taking" game, in which a team of two players attempt to make 3 tricks and win the hand.  A trick consists of
every player playing one card.  

The scoring is based on a team calling the hand, and whether that calling team makes 3 or 5 tricks.  For taking 3 tricks, the 
team receives 1 point, and for taking 5 tricks the team receives 2 points.  If one team "euchres" the other team (stops the 
calling team from winning the hand), that team receives two points.  Also, a player may declare that he will play his hand 
alone, and will receive 4 points for his team if he wins all five tricks.

Play proceeds with each player having a chance to declare whether or not he can take the hand, based on the trump of the turn
card.  If all reject this, the turn card is turned over, and each player then has an opportunity to name a trump for his team.

The only rule for a play to be legal, is that if a player may "follow suit" (play a card of the same suit as the card lead), 
he must do so.  The winner is each trick is the player who plays the highest card of the suit lead, unless the trick is 
"trumped" in which case, the highest trump takes the hand.

First team to score 10 points wins the game.
