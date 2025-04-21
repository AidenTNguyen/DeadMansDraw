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

}

void Cannon::willAddToBank(Game& game, const Player& player) {

}