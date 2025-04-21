#include "Hook.h"
#include "Player.h"

using namespace std;

Hook::Hook(int _value)
    : Card(CardType::Hook), value(_value)
{
}

int Hook::getValue() const {
    return value;
}

Card::CardType Hook::type() const {
    return cardType;
}

std::string Hook::str() const {
    return "Hook(" + std::to_string(getValue()) + ")";
}

void Hook::play(Game& game, Player& player) {
    std::cout << "  Select a highest-value card from any of the suits in your Bank:" << std::endl;

    int index = 1;
    for (const auto& card : player.getBank()) {
        std::cout << "(" << index++ << ") " << card->str() << std::endl; // Print it out
    }

    int highestValue = -1;
    int highestIndex = -1;

    index = 0; // dont think it matters if we  reuse this

    for (const auto& card : player.getBank()) {
        int cardValue = card->getValue();
        if (cardValue > highestValue)
    }
}

void Hook::willAddToBank(Game& game, const Player& player) {

}