
## Sandesh Pathak

##### BLACKJACK 



### Class Card

## Get value
## Get suit 
## Get rank
## Set value


###Class Deck
Description:
A container of cards.
Data:
Size - how many cards in deck
Remaining - how many cards left
Methods:
Deal - remove a card from the deck
Shuffle - re-arrange the cards in some random fashion
Reset - go back to initial state with all cards

###Class Hand
Description:
A container of cards
Data:
Size - how many cards in deck
Remaining - how many cards left
Methods:
Shuffle - re-arrange the cards in some random fashion
Sort - put cards in some order
Discard - remove a card (based on some choice, not randomly like deal a card)

###Class Player
Description:
Represents a single player as part of (in this case) a Black Jack game.
Data:
Bank - how much money she has
Name - some identifier
Hand - instance of a card container class
Total - Total count of values of cards in hand ( WAIT!! ... does this belong here?)

Methods:
Bet - remove money from bank.
Win - add money to bank.
Hit - add a card to hand.

###Class Game
Description:
In charge of the black jack game.
When the dealer deals.
When the dealer hits.
When the dealer awards winnings 
Who gets the next card.
Data:
Players - Vector of player classes?
Dealer - Dealer class? Or use player class?
Deck - Does this go here?

Methods:
Print - prints current state to console
AcceptBets - ??
Deal - start round off
