#include "Sword.h"
#include "Player.h"

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
    std::cout << player.getName() << " draws a " << str() << std::endl;
}

void Sword::willAddToBank(Game& game, const Player& player) {

}