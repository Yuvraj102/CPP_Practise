#include "Yuvraj_Sept25_task2_Deckofcards.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

DeckOfCards::DeckOfCards() {
    for (int s = 0; s < 4; s++) {
        for (int f = 0; f < 13; f++) {
            deck.push_back(Card(f, s));
        }
    }
    currentCard = 0;
    std::srand(static_cast<unsigned>(std::time(0)));
}

void DeckOfCards::shuffle() {
    for (size_t i = 0; i < deck.size(); i++) {
        int j = rand() % deck.size();
        std::swap(deck[i], deck[j]);
    }
    currentCard = 0; // reset dealing
}

Card DeckOfCards::dealCard() {
    if (moreCards()) {
        return deck[currentCard++];
    }
    return Card(); // return default if no cards
}

bool DeckOfCards::moreCards() const {
    return currentCard < deck.size();
}
