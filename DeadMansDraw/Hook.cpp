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

    CardCollection& bank = player.getBank();

    if (bank.empty()) {
        std::cout << " No cards in your Bank. Play continues." << std::endl;
        return;
    }

    std::cout << "  Select a highest-value card from any of the suits in your Bank:" << std::endl;

    std::map<Card::CardType, std::pair<int, size_t>> highestCards; // Maps suit to {value, index}

    // Find the highest value card of each suit
    for (size_t i = 0; i < bank.size(); i++) {
        if (!bank[i]) continue; // Skip null pointers

        Card::CardType suit = bank[i]->type();
        int cardValue = bank[i]->getValue();

        if (highestCards.find(suit) == highestCards.end() ||
            cardValue > highestCards[suit].first) {
            highestCards[suit] = { cardValue, i };
        }
    }

    // vector of the suits and their highest values for display
    std::vector<std::pair<Card::CardType, std::pair<int, size_t>>> choices;
    for (const auto& pair : highestCards) {
        choices.push_back(pair);
    }

    for (int i = 0; i < choices.size(); ++i) {
        size_t bankIndex = choices[i].second.second;
        std::cout << "(" << (i + 1) << ") " << bank[bankIndex]->str() << std::endl;
    }

    // Get player's choice
    int choice = 0;
    std::cout << " Which card do you pick? ";
    std::cin >> choice;

    if (choice >= 1 && choice <= choices.size()) {
        // Get the index of the chosen card in the bank
        size_t bankIndex = choices[choice - 1].second.second;

        // extract the card from the bank
        std::unique_ptr<Card> chosenCard = std::move(bank[bankIndex]);

        // remove the null pointer from the bank
        bank.erase(bank.begin() + bankIndex);

        // play the chosen card
        player.playCard(std::move(chosenCard), game);
    }
    else {
        std::cout << "Invalid choice. Try again." << std::endl;
    }
}

void Hook::willAddToBank(Game& game, const Player& player) {

}