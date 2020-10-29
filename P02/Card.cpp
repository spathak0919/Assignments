#include "Card.hpp"

Card::Card(int suit, int Value, int rank)
{
	this->suit = suit;
	this->Value = Value;
	this->rank = rank;
}

//setters and getters
int Card::GetRank()       //  get rank
{
	return rank;
}

int Card::GetVal()      //  get value
{
	return Value;
}

int Card::GetSuit()      // get suit
{
	return suit;
}

void Card::SetAceVal(int val)   //  set value
{
	Value=val;
}
