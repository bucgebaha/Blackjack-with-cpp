#include "Card.h"

    void Card::setValue(int _value) {
        this->value = _value;
    }
    int Card::getValue() {
        return this->value;
    }

    void Card::setSymbol(std::string _symbol) {
        this->symbol = _symbol;
    }
    std::string Card::getSymbol() {
        return this->symbol;
    }

    void Card::setSuit(char _suit) {
        this->suit = _suit;
    }
    char Card::getSuit() {
        return this->suit;
    }

    Card::Card() {
        setValue(0);
        setSymbol("0");
        setSuit('0');
    }