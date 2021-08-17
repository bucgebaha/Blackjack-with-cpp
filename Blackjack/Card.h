#pragma once
#include <iostream>

class Card {
private:
    int value;
    std::string symbol;
    char suit;
public:
    void setValue(int _value);
    int getValue();
    void setSymbol(std::string _symbol);
    std::string getSymbol();
    void setSuit(char _suit);
    char getSuit();
    Card();
};