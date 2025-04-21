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
}

void Map::willAddToBank(Game& game, const Player& player) {

}