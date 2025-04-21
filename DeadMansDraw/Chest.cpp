#include "Chest.h"
#include "Player.h"
#include "Game.h"

using namespace std;

Chest::Chest(int _value)
    : Card(CardType::Chest), value(_value)
{
}

int Chest::getValue() const {
    return value;
}

Card::CardType Chest::type() const {
    return cardType;
}

std::string Chest::str() const {
    return "Chest(" + std::to_string(getValue()) + ")";
}

void Chest::play(Game& game, Player& player) {
    std::cout << "  No immediate effect. If banked with a key, draw as many bonus cards from the discard pile as you moved into your Bank." << std::endl;
}

void Chest::willAddToBank(Game& game, Player& player) {
    
    bool hasKey = false;
    CardCollection& bank = player.getBank();

    for (const auto& card : bank) {
        if (card && card->type() == Card::CardType::Key) {
            hasKey = true;
            break;
        }
    }

    if (hasKey) {
        const CardCollection& playArea = player.getPlayArea();
        int cardsToAdd = playArea.size();

        CardCollection& discardPile = game.getDiscardPile();

        // are there enough cards in the discard pile
        int availableCards = std::min(cardsToAdd, static_cast<int>(discardPile.size()));

        if (availableCards == 0) {
            std::cout << " Chest and key activated, No cards in the discard pile" << std::endl;
            return;
        }
    }

}