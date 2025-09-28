/*
(Card Shuffling and Dealing) Create a program to shuffle and deal a deck of cards. The pro- gram should consist of class Card, class DeckOfCards and a driver program. Class Card should provide:
a) Data members face and suit of type int.
b) Aconstructorthatreceivestwointsrepresentingthefaceandsuitandusesthemtoini-
tialize the data members.
c) Two static arrays of strings representing the faces and suits.
d) A toString function that returns the Card as a string in the form “face of suit.” You
can use the + operator to concatenate strings.
Class DeckOfCards should contain:
a) A vector of Cards named deck to store the Cards.
b) AnintegercurrentCardrepresentingthenextcardtodeal.
c) A default constructor that initializes the Cards in the deck. The constructor should use
vector function push_back to add each Card to the end of the vector after the Card is
created and initialized. This should be done for each of the 52 Cards in the deck.
d) A shuffle function that shuffles the Cards in the deck. The shuffle algorithm should iterate through the vector of Cards. For each Card, randomly select another Card in the
deck and swap the two Cards.
e) A dealCard function that returns the next Card object from the deck.
f) A moreCards function that returns a bool value indicating whether there are more Cards
to deal.
The driver program should create a DeckOfCards object, shuffle the cards, then deal the 52 cards.
*/

#include <iostream>
#include "Yuvraj_Sept25_task2_Deckofcards.h"

int main() {
    DeckOfCards deck;

    std::cout << "Shuffling deck...\n\n";
    deck.shuffle();

    int count = 0;
    while (deck.moreCards()) {
        std::cout << deck.dealCard().toString() << "\n";
        if (++count % 4 == 0) std::cout << "\n"; // format 4 per line
    }

    return 0;
}
