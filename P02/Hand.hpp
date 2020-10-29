#ifndef HAND_HPP
#define HAND_HPP

#include "Player.hpp"
#include "Deck.hpp"

class Hand: public Player{
	public:
		Hand(int shownTotal);
		Card* Deal();
		void UpdateTotal();
		int PlayTurn();
	private:
		Deck* deck;
		int hiddenTotal;
};

#endif
