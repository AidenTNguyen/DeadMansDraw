#include "Map.h"
#include "Player.h"
#include "Game.h"

using namespace std;

Map::Map(int _value)
    : Card(CardType::Map), value(_value)
{
}

int Map::getValue() const {
    return value;
}

Card::CardType Map::type() const {
    return cardType;
}

std::string Map::str() const {
    return "Map(" + std::to_string(getValue()) + ")";
}

void Map::play(Game& game, Player& player) {
    std::cout << "  Draw 3 cards from the discard pile and pick one to add to the play area" << std::endl;

    // Check if there are cards in the discard pile
    CardCollection& discardPile = game.getDiscardPile();
    if (discardPile.empty()) {
        std::cout << "  The discard pile is empty. Play continues." << std::endl;
        return;
    }

    int availableCards = std::min(3, static_cast<int>(discardPile.size()));

    // temporary storage for the drawn cards
    std::vector<std::unique_ptr<Card>> drawnCards;

    // draw up to 3
    for (int i = 0; i < availableCards; i++) {
        drawnCards.push_back(std::move(discardPile.back()));
        discardPile.pop_back();
    }

    for (int i = 0; i < drawnCards.size(); i++) {
        std::cout << "  (" << (i + 1) << ") " << drawnCards[i]->str() << std::endl; // display, should display as many as possible and not short circuit and die
    }

}

void Map::willAddToBank(Game& game, const Player& player) {

}