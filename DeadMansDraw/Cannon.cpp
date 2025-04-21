#include "Cannon.h"
#include "Player.h"
#include "Game.h"
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
}

void Cannon::willAddToBank(Game& game, const Player& player) {

}