
#include <iostream>
#include <cstdlib>
#include <string>
#include "Game.hpp"
#include "Hand.hpp"
using namespace std;

void Hit(Hand* dealer, Player* player);
void DealOpeningHands(Hand* dealer, Player* player);
void PrintHand(Player* player);

int main()
{
  int bet;
	Hand* dealer = new Hand(0);
	User* user = new User(0);

	cout<<"\033[0;34;47m"<<"Welcome to Blackjack."<<endl;
  cout<<"\033[0;39;49m""Enter your bet :"<<endl;
  cin >>bet;
 
  if(bet>1000)
  {
    cout<<"not enough balance";
  }
  else if(bet<1000)
  {
  cout<<"DEALT CARDS"<<endl;
  }
  
	DealOpeningHands(dealer, user);
	PrintHand(user);
	int usrOption = -1;
	do
  {
    cout <<endl;
		cout<<" Enter 1 to HIT   "<<endl;
    cout<<" Enter 2 to STAND "<<endl;
    cout<<" Enter 0 to EXIT  "<<endl;
    cout <<endl;
	  cin>> usrOption;
		if (usrOption==1)
    {
			Hit(dealer, user);
			PrintHand(user);
			if (user->shownTotal > 21)
      {
				cout<<"Bust!"<<endl;
        cout<<"YOU LOSE"<<endl;

				break;
			}
		} else if (usrOption==2)
    {
			cout<<"Dealer plays:"<<endl;
			int dealerTotal = dealer->PlayTurn();
			PrintHand(dealer);
			if (dealerTotal == -1)
      {
				cout<<"Dealer busts!"<<endl;
			}
      else 
      {
			cout<<"Dealer total sum "<<dealerTotal<<endl;
			}
			if (dealerTotal > user->shownTotal)
      {
				cout<<"Dealer wins!"<<endl;
			}
       else if (dealerTotal == user->shownTotal)
      {
				cout<<"Tie!"<<endl;
			} else 
      {
			cout<<"YOU WIN!"<<endl;
			}
			break;
		}
     else
    {
		}
	} while (usrOption != 0);		
}

void Hit(Hand* dealer, Player* player)
{
	player->hand.push_back(dealer->Deal());
	player->UpdateTotal();
}

void DealOpeningHands(Hand* dealer, Player* player)
{
	player->hand.push_back(dealer->Deal());
	player->hand.push_back(dealer->Deal());
	dealer->hand.push_back(dealer->Deal());
	dealer->hand.push_back(dealer->Deal());
	player->UpdateTotal();
	dealer->UpdateTotal();
}

void PrintHand(Player* player)
{
	for (Card* card: player->hand)
  {
		int suitNum = card->GetSuit();
	  string suitName = "broken";
		if (suitNum==0)
    {
			suitName="Hearts";
		} 
    else if (suitNum==1)
    {
			suitName="Clubs";
		} 
    else if (suitNum==2)
    {
			suitName="Diamonds";
		}
     else
    {
			suitName="Spades";
		}

		int rank = card->GetRank();

		string rankName = "rank";
		if (rank==11)
    {
			rankName="J";
		} 
    else if (rank==12)
    {
			rankName="Q";
		} 
    else if (rank==13)
    {
			rankName="K";
		} 
    else if (rank==14)
    {
			rankName="A";
		}
     else 
    {
			rankName=to_string(rank);
		}
	cout<<rankName<<" "<<suitName<<" ";
	}
	cout<<endl;
}


	
