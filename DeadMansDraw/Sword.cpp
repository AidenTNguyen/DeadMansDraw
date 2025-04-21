#include "Sword.h"

using namespace std;

Sword::Sword(int _value)
    : Card(CardType::Sword), value(_value)
{
}

int Sword::getValue() const {
    return value;
}

Card::CardType Sword::type() const {
    return cardType;
}

std::string Sword::str() const {
    return "Sword(" + std::to_string(getValue()) + ")";
}

void Sword::play(Game& game, Player& player) {

}

void Sword::willAddToBank(Game& game, const Player& player) {

}