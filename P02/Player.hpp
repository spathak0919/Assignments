#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Card.hpp"
#include <vector>

class Player {
	public:
		int shownTotal;
		Player(int shownTotal);
		std::vector<Card*> hand;
		virtual void UpdateTotal()=0;
		bool acePresent;
};

#endif
