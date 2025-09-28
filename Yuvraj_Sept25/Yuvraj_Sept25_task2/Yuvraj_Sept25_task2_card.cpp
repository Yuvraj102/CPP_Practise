#include "Yuvraj_Sept25_task2_card.h"

// initialize static arrays
const std::string Card::faces[13] =
    {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
     "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

const std::string Card::suits[4] =
    {"Clubs", "Diamonds", "Hearts", "Spades"};

Card::Card(int f, int s) : face(f), suit(s) {}

std::string Card::toString() const {
    return faces[face] + " of " + suits[suit];
}
