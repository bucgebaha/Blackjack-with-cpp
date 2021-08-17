#pragma once
#include "Card.h"

class Hand {
private:
    int totalValue;
    int aceCounter;
    Card cards[11]; // If you draw the lowest cards until you hit 21, you will have 11 cards (4x aces, 4x twoes and 3x threes.) and this is the maximum amount of cards that could be drawn. That's why this list have 11 elements.
    int cardsDrawn;
public:
    void setTotalValue(int _totalValue);
    void incTotalValueBy(int _increaseAmount);
    int getTotalValue();
    void aceDrawn();
    void useAceAsOne();
    void cardDrawn(int _value, std::string _symbol, char _suit);
    void printHand();
    void printHandFirstCardDown();
    bool doesBurst();
    Hand();
};

