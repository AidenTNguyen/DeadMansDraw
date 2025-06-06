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

void Chest::willAddToBank(Game& game, const Player& player) {

    Player& mutablePlayer = const_cast<Player&>(player);
    
    bool hasKey = false;
    CardCollection& playArea = mutablePlayer.getPlayArea();
    CardCollection& bank = mutablePlayer.getBank();

    for (const auto& card : playArea) {
        if (card && card->type() == Card::CardType::Key) {
            hasKey = true;
            break;
        }
    }

    if (hasKey) {
        const CardCollection& playArea = mutablePlayer.getPlayArea();
        int cardsToAdd = playArea.size();

        CardCollection& discardPile = game.getDiscardPile();

        // are there enough cards in the discard pile
        int availableCards = std::min(cardsToAdd, static_cast<int>(discardPile.size()));

        if (availableCards == 0) {
            std::cout << " Chest and key activated, No cards in the discard pile" << std::endl;
            return;
        }

        std::string drawnCardsStr = " ";

        for (int index = 0; index < availableCards; ++index) {
            
            // get card from discord pile
            std::unique_ptr<Card> drawnCard = std::move(discardPile.back());
            std::string cardName = drawnCard->str();
            discardPile.pop_back();

            if (index > 0) {
                drawnCardsStr += ", ";
            }
            drawnCardsStr += cardName;

            bank.push_back(std::move(drawnCard));
        }

        // Format the output as requested
        std::cout << "  Chest and key activated. Added " << drawnCardsStr << " to your bank." << std::endl;
        }
    

}