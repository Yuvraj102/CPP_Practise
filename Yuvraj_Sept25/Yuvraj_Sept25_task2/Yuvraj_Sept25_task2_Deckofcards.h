#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include <vector>
#include "Yuvraj_Sept25_task2_card.h"

class DeckOfCards {
public:
    DeckOfCards();              // constructor: builds deck
    void shuffle();             // shuffle cards
    Card dealCard();            // deal one card
    bool moreCards() const;     // true if more cards left

private:
    std::vector<Card> deck;
    int currentCard;            // index of next card
};

#endif
