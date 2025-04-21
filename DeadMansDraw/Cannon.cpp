#include "Cannon.h"
#include "Player.h"
#include "Game.h"
#include <map>

using namespace std;

Cannon::Cannon(int _value)
    : Card(CardType::Cannon), value(_value)
{}

int Cannon::getValue() const {
    return value;
}

Card::CardType Cannon::type() const {
    return cardType;
}

std::string Cannon::str() const {
    return "Cannon(" + std::to_string(getValue()) + ")";
}

void Cannon::play(Game& game, Player& player) {
    std::cout << player.getName() << " draws a " << str() << std::endl;

    // Find opponent
    Player* opponent = nullptr;
    auto& playerList = game.getPlayerList();
    for (auto& currentPlayer : playerList) {
        if (currentPlayer && currentPlayer->getName() != player.getName()) {
            opponent = currentPlayer.get();
            break;
        }
    }
    
    CardCollection& opponentBank = opponent->getBank();

    if (opponent->getBank().empty()) {
        std::cout << " Opponent's bank is empty, Play continues." << std::endl;
    }

    // Find highest value card of each suit in opponent's bank
    std::map<Card::CardType, std::pair<int, size_t>> highestCards; // Maps suit to {value, index}

    for (size_t i = 0; i < opponentBank.size(); i++) {
        if (!opponentBank[i]) continue; // Skip null pointers

        Card::CardType suit = opponentBank[i]->type();
        int cardValue = opponentBank[i]->getValue();

        // new suit or higher value
        if (highestCards.find(suit) == highestCards.end() ||
            cardValue > highestCards[suit].first) {
            highestCards[suit] = { cardValue, i };
        }
    }

    // vector for the key pair values
    std::vector<std::pair<Card::CardType, std::pair<int, size_t>>> choices;
    for (const auto& pair : highestCards) {
        choices.push_back(pair);
    }

    // display
    std::cout << "  Select a card to discard from " << opponent->getName() << "'s Bank:" << std::endl;
    for (int i = 0; i < choices.size(); ++i) {
        size_t bankIndex = choices[i].second.second;
        std::cout << "  (" << (i + 1) << ") " << opponentBank[bankIndex]->str() << std::endl;
    }

    int choice = 0;
    std::cout << "  Which card do you want to discard? ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the entire input buffer

}

void Cannon::willAddToBank(Game& game, const Player& player) {

}