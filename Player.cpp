#include "Player.h"

Player::Player(char symbol, std::string name)
    : symbol(symbol), name(name) {
}

char Player::getSymbol() const {
    return symbol;
}

std::string Player::getName() const {
    return name;
}
