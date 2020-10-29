
## Sandesh Pathak

##### BLACKJACK 



Class Card Description

Represents Values for a card.
Data

Rank - card ranks
Value - numerical value of card
Methods

SetRank
SetValue
GetRank
GetValue
Print
Class Deck Description

A container of cards.
Data

Size - number cards in deck
Remaining - cards left in deck
Methods

Deal - Remove a card from the deck.
Shuffle - Re-Arrange cards.
Reset - Go back to initial state of deck.
Class Hand Description

A container of cards.
Data

Size
Remaining
Methods

Shuffle - rearrange cards
Sort - set cards in order
Discard - remove card
Class Player Description

Class to represent a player
Data

Bank - player's money
Name - player's name
Hand - instance of hand class
Methods

Bet - subtract money
Win - add money
Hit - add deck to hand
Class Game AI Description

In charge of running the game
Data

Players - number of players playing
Dealer - dealer info
Methods

Print - Prints to console
deal - gets bets, distrubute cards
newRound - begins round
