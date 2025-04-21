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
    std::cout << player.getName() << " draws a " << str() << std::endl;

    int additionalDraws = 3;

    for (additionalDraws; additionalDraws != 0; additionalDraws--) {
        auto drawnCard = game.drawCard();
    }
}

void Kraken::willAddToBank(Game& game, const Player& player) {

}