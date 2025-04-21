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

    std::map<Card::CardType, size_t> highestCardIndices;

    // First find the highest value card for each suit
    for (size_t i = 0; i < player.getBank().size(); i++) {
        Card::CardType suit = player.getBank()[i]->type();
        int value = player.getBank()[i]->getValue();

        // If we haven't seen this suit yet or if hte card has a higher value
        if (highestCardIndices.find(suit) == highestCardIndices.end() ||
            player.getBank()[i]->getValue() > player.getBank()[highestCardIndices[suit]]->getValue()) {
            highestCardIndices[suit] = i;
        }
    }

    // Convert map to vector for display
    std::vector<size_t> displayIndices;
    for (const auto& pair : highestCardIndices) {
        displayIndices.push_back(pair.second);
    }

    
    for (size_t i = 0; i < displayIndices.size(); i++) {
        std::cout << "(" << (i + 1) << ") " << player.getBank()[displayIndices[i]]->str() << std::endl;
    }

    // Get player choice
    int choice;
    std::cout << " Which card do you pick? ";
    std::cin >> choice;

    if (choice < 1 || choice > static_cast<int>(displayIndices.size())) {
        std::cout << "Invalid choice. Try again." << std::endl;
        return;
    }

    // Get selected card index
    size_t selectedIndex = displayIndices[choice - 1];

    std::string cardInfo = player.getBank()[selectedIndex]->str();

    auto selectedCard = std::move(player.getBank()[selectedIndex]);
    player.getBank().erase(player.getBank().begin() + selectedIndex);

    player.playCard(std::move(selectedCard), game);
}

void Hook::willAddToBank(Game& game, const Player& player) {

}