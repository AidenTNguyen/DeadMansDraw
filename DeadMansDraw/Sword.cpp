#include "Sword.h"
#include "Player.h"
#include "Game.h"
#include <map>

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
    Player* opponent = nullptr;
    auto& playerList = game.getPlayerList();
    for (auto& p : playerList) {
        if (p && p->getName() != player.getName()) {
            opponent = p.get();
            break;
        }
    }

    CardCollection& opponentBank = opponent->getBank();

    if (opponentBank.empty()) {
        std::cout << "  No cards in other player's Bank. Play continues." << std::endl;
        return;
    }

    // 'nother map!
    std::map<Card::CardType, std::pair<int, size_t>> highestCards;

    // Find the highest value
    for (size_t i = 0; i < opponentBank.size(); i++) {
        if (!opponentBank[i]) continue; // Skip null pointers

        Card::CardType suit = opponentBank[i]->type();
        int cardValue = opponentBank[i]->getValue();

        if (highestCards.find(suit) == highestCards.end() ||
            cardValue > highestCards[suit].first) {
            highestCards[suit] = { cardValue, i };
        }
    }

    std::vector<std::pair<Card::CardType, std::pair<int, size_t>>> choices;
    for (const auto& pair : highestCards) {
        choices.push_back(pair);
    }

    // Display
    std::cout << "  Select a card to steal from " << opponent->getName() << "'s Bank:" << std::endl;
    for (int i = 0; i < choices.size(); ++i) {
        size_t bankIndex = choices[i].second.second;
        std::cout << "  (" << (i + 1) << ") " << opponentBank[bankIndex]->str() << std::endl;
    }

    // choice
    int choice = 0;
    std::cout << "  Which card do you want to steal? ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice >= 1 && choice <= choices.size()) {
        // Get the index of the chosen card in the opponent's bank
        size_t bankIndex = choices[choice - 1].second.second;

        // Extract the card from the opponent's bank
        std::unique_ptr<Card> stolenCard = std::move(opponentBank[bankIndex]);

        // Show what's being stolen
        std::cout << "  Stealing " << stolenCard->str() << " from " << opponent->getName() << "'s Bank." << std::endl;

        // Add the card to the player's play area
        player.getPlayArea().push_back(std::move(stolenCard));

        // Remove the null pointer from the opponent's bank
        opponentBank.erase(opponentBank.begin() + bankIndex);
    }
    else {
        std::cout << "  Invalid choice. No card stolen." << std::endl;
    }
}

void Sword::willAddToBank(Game& game, const Player& player) {

}