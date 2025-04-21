#include "Map.h"
#include "Player.h"

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
    std::cout << player.getName() << " draws a " << str() << std::endl;
}

void Map::willAddToBank(Game& game, const Player& player) {

}