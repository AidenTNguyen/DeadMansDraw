#include "Cannon.h"

using namespace std;

Cannon::Cannon(int _value)
    : Card(CardType::Cannon), value(_value)
{}

int Cannon::getValue() const {
    return value;
}

Card::CardType Cannon::type() const {
    return cardType;
}

std::string Cannon::str() const {
    return "";
}

void Cannon::play(Game& game, Player& player) {

}

void Cannon::willAddToBank(Game& game, const Player& player) {

}