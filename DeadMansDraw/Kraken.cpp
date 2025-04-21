#include "Kraken.h"
#include "Player.h"
#include "Game.h"

using namespace std;

Kraken::Kraken(int _value)
    : Card(CardType::Kraken), value(_value)
{
}

int Kraken::getValue() const {
    return value;
}

Card::CardType Kraken::type() const {
    return cardType;
}

std::string Kraken::str() const {
    return "Kraken(" + std::to_string(getValue()) + ")";
}

void Kraken::play(Game& game, Player& player) {
    std::cout << "  Draw 3 cards from the deck and play each:" << std::endl;

    int additionalDraws = 3;
    CardCollection& drawPile = game.getSharedDeck();

    for (additionalDraws; additionalDraws != 0; additionalDraws--) {

        if (drawPile.empty()) {
            std::cout << "Oh no were out of cards D:" << std::endl;
            break;
        }

        auto drawnCard = game.drawCard();

        bool busted = player.playCard(std::move(drawnCard), game);

        if (busted) {
            return;
        }
    }
}

void Kraken::willAddToBank(Game& game, const Player& player) {

}