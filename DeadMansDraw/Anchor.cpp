#include "Anchor.h"

using namespace std;

Anchor::Anchor(int _value)
    : Card(CardType::Anchor), value(_value), played(false)
{
}

int Anchor::getValue() const {
    return value;
}

Card::CardType Anchor::type() const {
    return cardType;
}

std::string Anchor::str() const {
    return "";
}

void Anchor::play(Game& game, Player& player) {

}

void Anchor::willAddToBank(Game& game, const Player& player) {

}