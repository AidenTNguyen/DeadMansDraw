#include "Key.h"

using namespace std;

Key::Key(int _value)
    : Card(CardType::Key), value(_value)
{
}

int Key::getValue() const {
    return value;
}

Card::CardType Key::type() const {
    return cardType;
}

std::string Key::str() const {
    return "";
}

void Key::play(Game& game, Player& player) {

}

void Key::willAddToBank(Game& game, const Player& player) {

}