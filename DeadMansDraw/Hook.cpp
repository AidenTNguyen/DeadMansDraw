#include "Hook.h"
#include "Player.h"
#include <map>

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

    std::map<std::string, std::vector<std::unique_ptr<Card>>> suitGroups;

    for (auto& card : player.getBank()) {
        Card::CardType suit = card->type();
        suitGroups[static_cast<int>(suit)].push_back(std::move(card));
    }

}

void Hook::willAddToBank(Game& game, const Player& player) {

}