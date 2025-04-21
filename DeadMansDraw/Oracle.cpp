#include "Oracle.h"
#include "Player.h"

using namespace std;

Oracle::Oracle(int _value)
    : Card(CardType::Oracle), value(_value)
{
}

int Oracle::getValue() const {
    return value;
}

Card::CardType Oracle::type() const {
    return cardType;
}

std::string Oracle::str() const {
    return "Oracle(" + std::to_string(getValue()) + ")";
}

void Oracle::play(Game& game, Player& player) {

}

void Oracle::willAddToBank(Game& game, const Player& player) {

}