#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    Card(int face = 0, int suit = 0);

    std::string toString() const;

private:
    int face;  // 0-12 (Ace..King)
    int suit;  // 0-3 (Clubs, Diamonds, Hearts, Spades)

    static const std::string faces[13];
    static const std::string suits[4];
};

#endif
