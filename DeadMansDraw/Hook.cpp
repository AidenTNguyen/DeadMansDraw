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

    if (player.getBank().empty()) {
        std::cout << " No cards in your Bank. Play continues." << std::endl;
        return;
    }

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

        highestCards.push_back(std::move(*maxCardIterator));
    }

    for (int i = 0; i < highestCards.size(); ++i) {
        std::cout << "(" << (i + 1) << ") " << highestCards[i]->str() << std::endl;
    }

    // choice time!
    int choice = 0;
    std::cout << " Which card do you pick? ";
    std::cin >> choice;

    // Might as well make sure its valid
    if (choice >= 1 && choice <= highestCards.size()) {
        auto chosenCard = std::move(highestCards[choice - 1]);
        player.playCard(std::move(chosenCard), game);
    }
    else {
        std::cout << "Invalid choice. Try again." << std::endl;
    }

}

void Hook::willAddToBank(Game& game, const Player& player) {

}