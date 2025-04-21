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
    std::cout << "  Steal the top card of any suit from the other player's Bank into your play area" << std::endl;

    // Find the opponent

    //if (opponentBank.empty()) {
    //    std::cout << "  No cards in other player's Bank. Play continues." << std::endl;
    //    return;
    //}
}

void Sword::willAddToBank(Game& game, const Player& player) {

}