#include "Table.h"
#include <string>

void Table::printTableAllRevealed() {
    std::cout << "Dealer's hand: "; dealerHand.printHand(); std::cout << "\n";
    std::cout << "Your hand: "; playerHand.printHand(); std::cout << "\n";
}
void Table::printTable() {
    std::cout << "Dealer's hand: "; dealerHand.printHandFirstCardDown(); std::cout << "\n";
    std::cout << "Your hand: "; playerHand.printHand(); std::cout << "\n";
}
void Table::hit(Hand& _hand) {
    std::string symbol;
    int value;
    char suit;

    bool hasDrawnBefore = false;

    do {
        int randomSymbolAndValue = rand() % 13 + 1;
        int randomSuit = rand() % 4 + 1;

        switch (randomSuit)
        {
        case 1:
            suit = 3;
            break;
        case 2:
            suit = 4;
            break;
        case 3:
            suit = 5;
            break;
        case 4:
            suit = 6;
            break;
        default:
            suit = '!';
            break;
        }

        if (randomSymbolAndValue > 1 && randomSymbolAndValue <= 10) {
            value = randomSymbolAndValue;
            symbol = std::to_string(value);
        }
        else if (randomSymbolAndValue == 11) {
            symbol = 'J';
            value = 10;
        }
        else if (randomSymbolAndValue == 12) {
            symbol = 'Q';
            value = 10;
        }
        else if (randomSymbolAndValue == 13) {
            symbol = 'K';
            value = 10;
        }
        else if (randomSymbolAndValue == 1) {
            symbol = 'A';
            value = 11;
        }

        for (int i = 0; i < cardCounter; i++)
        {
            if (cardsOnTable[i].getSymbol() == symbol && cardsOnTable[i].getSuit() == suit) {
                hasDrawnBefore = true;
                break;
            }
            else hasDrawnBefore = false;
        }
    } while (hasDrawnBefore);

    _hand.cardDrawn(value, symbol, suit);

    cardsOnTable[cardCounter].setSuit(suit);
    cardsOnTable[cardCounter].setSymbol(symbol);
    this->cardCounter++;
    _hand.doesBurst();
}
void Table::startTheGame() {
    hit(playerHand);
    hit(dealerHand);
    hit(playerHand);
    hit(dealerHand);
    printTable();
}
void Table::dealerDraws() {
    while (dealerHand.getTotalValue() < 17 && !playerHand.doesBurst()) {
        hit(dealerHand);
        std::cout << "\n---DEALER DRAWS---\n\n";
        printTableAllRevealed();
    }
}
void Table::declareTheWinner() {
    if (!playerHand.doesBurst() && (playerHand.getTotalValue() > dealerHand.getTotalValue() || dealerHand.doesBurst())) std::cout << "\n--- YOU WON! ---\n";
    else if (!playerHand.doesBurst() && !dealerHand.doesBurst() && playerHand.getTotalValue() == dealerHand.getTotalValue()) std::cout << "\n--- DRAW! ---\n";
    if (!dealerHand.doesBurst() && (dealerHand.getTotalValue() > playerHand.getTotalValue() || playerHand.doesBurst())) std::cout << "\n--- YOU LOST! ---\n";
}
Table::Table() {
    this->cardCounter = 0;
}