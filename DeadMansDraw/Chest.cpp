#include "Chest.h"

using namespace std;

Chest::Chest(int _value)
    : Card(CardType::Chest), value(_value)
{
}

int Chest::getValue() const {
    return value;
}

Card::CardType Chest::type() const {
    return cardType;
}

std::string Chest::str() const {
    return "Chest(" + std::to_string(getValue()) + ")";
}

void Chest::play(Game& game, Player& player) {

}

void Chest::willAddToBank(Game& game, const Player& player) {

}