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

    std::map<Card::CardType, std::vector<std::unique_ptr<Card>>> suitGroups;

    for (auto& card : player.getBank()) {
        Card::CardType suit = card->type();

        // Create a group for the suit if it doesn't exist
        suitGroups[suit].push_back(std::move(card));
    }

    std::vector<std::unique_ptr<Card>> highestCards;

    for (auto& suitGroup : suitGroups) {
        auto& group = suitGroup.second;
        auto maxCardIterator = std::max_element(group.begin(), group.end(), [](const std::unique_ptr<Card>& cardA, const std::unique_ptr<Card>& cardB) {
            return cardA->getValue() < cardB->getValue();
            });
    }

}

void Hook::willAddToBank(Game& game, const Player& player) {

}