#include "Kraken.h"

using namespace std;

Kraken::Kraken(int _value)
    : Card(CardType::Kraken), value(_value)
{
}

int Kraken::getValue() const {
    return value;
}

Card::CardType Kraken::type() const {
    return cardType;
}

std::string Kraken::str() const {
    return "";
}

void Kraken::play(Game& game, Player& player) {

}

void Kraken::willAddToBank(Game& game, const Player& player) {

}