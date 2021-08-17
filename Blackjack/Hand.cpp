#include "Hand.h"

void Hand::setTotalValue(int _totalValue) {
    this->totalValue = _totalValue;
}
void Hand::incTotalValueBy(int _increaseAmount) {
    this->totalValue += _increaseAmount;
}
int Hand::getTotalValue() {
    return this->totalValue;
}

void Hand::aceDrawn() {
    this->aceCounter++;
}
void Hand::useAceAsOne() {
    this->totalValue -= 10;
    this->aceCounter -= 1;
}

void Hand::cardDrawn(int _value, std::string _symbol, char _suit) {
    cards[cardsDrawn].setValue(_value);
    cards[cardsDrawn].setSymbol(_symbol);
    cards[cardsDrawn].setSuit(_suit);

    incTotalValueBy(_value);
    this->cardsDrawn++;
    if (_symbol == "A") this->aceCounter++;
}

void Hand::printHand() {
    for (int i = cardsDrawn; i > 0; i--) {
        std::cout << this->cards[this->cardsDrawn - i].getSuit() << " " << this->cards[this->cardsDrawn - i].getSymbol() << ", ";
    }

    std::cout << "total: " << totalValue;
}

void Hand::printHandFirstCardDown() {
    std::cout << "? " << "? , ";
    std::cout << this->cards[0].getSuit() << " " << this->cards[0].getSymbol() << ", ";

    std::cout << "total: ?";
}

bool Hand::doesBurst() {
    if (this->getTotalValue() > 21) {
        if (this->aceCounter > 0) {
            this->useAceAsOne();
            return false;
        }
        else return true;
    }
    else return false;
}

Hand::Hand() {
    this->aceCounter = 0;
    this->cardsDrawn = 0;
    this->totalValue = 0;
}