#include "Key.h"
#include "Player.h"

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
    return "Key(" + std::to_string(getValue()) + ")";
}

void Key::play(Game& game, Player& player) {
    std::cout << "  No immediate effect. If banked with a chest, draw as many bonus cards from the discard pile as you moved into your Bank." << std::endl;
}

void Key::willAddToBank(Game& game, const Player& player) {

}