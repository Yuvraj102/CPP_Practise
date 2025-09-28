#ifndef POKERHAND_H
#define POKERHAND_H

#include <vector>
#include "Yuvraj_Sept25_task2_card.h"


int getFace() const { return face; }
int getSuit() const { return suit; }


namespace Poker {
    bool hasPair(const std::vector<Card>& hand);
    bool hasTwoPair(const std::vector<Card>& hand);
    bool hasThreeOfKind(const std::vector<Card>& hand);
    bool hasFourOfKind(const std::vector<Card>& hand);
    bool hasFlush(const std::vector<Card>& hand);
    bool hasStraight(const std::vector<Card>& hand);

    int evaluateHand(const std::vector<Card>& hand); 
    std::string handName(int rank);
}

#endif
