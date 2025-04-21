#include "Anchor.h"
#include "Player.h"

using namespace std;

Anchor::Anchor(int _value)
    : Card(CardType::Anchor), value(_value), played(false)
{
}

int Anchor::getValue() const {
    return value;
}

Card::CardType Anchor::type() const {
    return cardType;
}

std::string Anchor::str() const {
    return "Anchor(" + std::to_string(getValue()) + ")";
}

void Anchor::play(Game& game, Player& player) {
    if (!played) {
        std::cout << "  Lucky days! Anchor has saved the cards drawn before it! :O <3" << str() << std::endl;
    

        played = true;

        // Find all cards in the play area that come before this Anchor
        CardCollection& playArea = player.getPlayArea();
        CardCollection& bank = player.getBank();

    }
    else {
        // already played
    }
    
}

void Anchor::willAddToBank(Game& game, const Player& player) {

}