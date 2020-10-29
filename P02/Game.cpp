#include "Game.hpp"

User::User(int shownTotal) : Player(shownTotal){
}

void User::UpdateTotal()
{
	int sum = 0;
	for (Card* card: hand)
  {
		if (card->GetRank()==14)
    {
			sum += 1;
			acePresent=true;
		} 
    else
    {
			sum += card->GetVal();
		}
	}
	shownTotal = sum;
	if (shownTotal<12 && acePresent){
		shownTotal += 10;
	}
}
