#ifndef CARD_HPP
#define CARD_HPP

class Card    // class card
{
	public:
		Card(int suit, int Value, int rank);  //constructor

		int GetVal();
		int GetSuit();
		int GetRank();
		void SetAceVal(int val);

	private:

		int suit;       // initiaize suit
		int Value;      // initialize value
		int rank;       // initialize rank
		
};

#endif
