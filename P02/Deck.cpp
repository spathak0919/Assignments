#include "Deck.hpp"
#include <random>
#include <chrono>
#include <algorithm>

Deck::Deck()        // remove a card from the deck
{
	currentTop = 0;
	for (int suit=0; suit<4; suit++)
  {
		for (int face=1; face<15; face++)
    {
			if (face==14)
      {
				cards.push_back(new Card(suit, -99, face));
      } 
      else if (face<14 && face>9)
      {
				cards.push_back(new Card(suit, 10, face));
			} else
       {
				cards.push_back(new Card(suit, face, face));
			}
		}
	}
}

void Deck::Shuffle()    //  re-arrange the cards in some random fashion
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}

Card* Deck::Reset()   // go back to initial state with all cards
{
	Card* topCard = cards[currentTop];
	currentTop++;
	return topCard;
}
