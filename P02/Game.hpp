#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"

class User:public Player{
	public:
		User(int shownTotal);
		void UpdateTotal();
};

#endif
