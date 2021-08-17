#pragma once
#include "Card.h"
#include "Hand.h"

class Table {
private:
    Card cardsOnTable[17]; // If the player and dealer draw the lowest cards until they hit 21 or burst, they will have 17 cards (4x aces, 4x twoes, 4x threes, 4x fours, 1x five) and this is the maximum amount of cards that could be drawn. That's why this list have 17 elements.
    int cardCounter;
public:
    Hand dealerHand;
    Hand playerHand;

    void printTableAllRevealed();
    void printTable();
    void hit(Hand& _hand);
    void startTheGame();
    void dealerDraws();
    void declareTheWinner();
    Table();
};