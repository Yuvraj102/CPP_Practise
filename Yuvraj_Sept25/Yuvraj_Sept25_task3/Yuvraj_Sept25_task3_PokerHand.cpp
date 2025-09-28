#include "Yuvraj_Sept25_task3_PokerHand.h"
#include <map>
#include <algorithm>

// helper: count frequencies of faces
static std::map<int,int> faceCount(const std::vector<Card>& hand) {
    std::map<int,int> freq;
    for (auto &c : hand) freq[c.getFace()]++;
    return freq;
}

// helper: count frequencies of suits
static std::map<int,int> suitCount(const std::vector<Card>& hand) {
    std::map<int,int> freq;
    for (auto &c : hand) freq[c.getSuit()]++;
    return freq;
}

bool Poker::hasPair(const std::vector<Card>& hand) {
    auto freq = faceCount(hand);
    for (auto &p : freq)
        if (p.second == 2) return true;
    return false;
}

bool Poker::hasTwoPair(const std::vector<Card>& hand) {
    auto freq = faceCount(hand);
    int pairs = 0;
    for (auto &p : freq)
        if (p.second == 2) pairs++;
    return pairs == 2;
}

bool Poker::hasThreeOfKind(const std::vector<Card>& hand) {
    auto freq = faceCount(hand);
    for (auto &p : freq)
        if (p.second == 3) return true;
    return false;
}

bool Poker::hasFourOfKind(const std::vector<Card>& hand) {
    auto freq = faceCount(hand);
    for (auto &p : freq)
        if (p.second == 4) return true;
    return false;
}

bool Poker::hasFlush(const std::vector<Card>& hand) {
    auto freq = suitCount(hand);
    return (freq.begin()->second == 5);
}

bool Poker::hasStraight(const std::vector<Card>& hand) {
    std::vector<int> faces;
    for (auto &c : hand) faces.push_back(c.getFace());
    std::sort(faces.begin(), faces.end());
    // Ace-low straight: A(0),1,2,3,4 -> treat Ace as 13
    if (faces == std::vector<int>{0,1,2,3,12}) return true;
    for (int i = 1; i < faces.size(); i++) {
        if (faces[i] != faces[i-1] + 1) return false;
    }
    return true;
}

// Rank order: higher int = stronger hand
// 6 = Straight flush, 5 = Four of a kind, 4 = Full house,
// 3 = Flush, 2 = Straight, 1 = Three of a kind, 0 = Two pair,
// -1 = One pair, -2 = High card
int Poker::evaluateHand(const std::vector<Card>& hand) {
    bool flush = hasFlush(hand);
    bool straight = hasStraight(hand);
    if (flush && straight) return 6;
    if (hasFourOfKind(hand)) return 5;
    if (hasThreeOfKind(hand) && hasPair(hand)) return 4; // full house
    if (flush) return 3;
    if (straight) return 2;
    if (hasThreeOfKind(hand)) return 1;
    if (hasTwoPair(hand)) return 0;
    if (hasPair(hand)) return -1;
    return -2; // high card
}

std::string Poker::handName(int rank) {
    switch(rank) {
        case 6: return "Straight Flush";
        case 5: return "Four of a Kind";
        case 4: return "Full House";
        case 3: return "Flush";
        case 2: return "Straight";
        case 1: return "Three of a Kind";
        case 0: return "Two Pair";
        case -1: return "One Pair";
        default: return "High Card";
    }
}
