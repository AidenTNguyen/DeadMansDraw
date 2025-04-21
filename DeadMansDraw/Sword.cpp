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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the entire input buffer
}

void Sword::willAddToBank(Game& game, const Player& player) {

}