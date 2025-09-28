#include <iostream>
#include <vector>
#include "Yuvraj_Sept25_task3_Deckofcards.h"
#include "Yuvraj_Sept25_task3_PokerHand.h"

// TO solve later 


int main() {
    DeckOfCards deck;
    deck.shuffle();

    std::vector<Card> hand1, hand2;

    // deal 5 cards each
    for (int i = 0; i < 5; i++) hand1.push_back(deck.dealCard());
    for (int i = 0; i < 5; i++) hand2.push_back(deck.dealCard());

    std::cout << "Hand 1:\n";
    for (auto &c : hand1) std::cout << "  " << c.toString() << "\n";
    int rank1 = Poker::evaluateHand(hand1);
    std::cout << "-> " << Poker::handName(rank1) << "\n\n";

    std::cout << "Hand 2:\n";
    for (auto &c : hand2) std::cout << "  " << c.toString() << "\n";
    int rank2 = Poker::evaluateHand(hand2);
    std::cout << "-> " << Poker::handName(rank2) << "\n\n";

    if (rank1 > rank2) std::cout << "Hand 1 wins!\n";
    else if (rank2 > rank1) std::cout << "Hand 2 wins!\n";
    else std::cout << "It's a tie!\n";

    return 0;
}
