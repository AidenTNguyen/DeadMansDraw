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
        std::cout << "  Lucky days! Anchor has saved the cards drawn before it! :O <3" << std::endl;
    
        played = true;

        // Find all cards in the play area that come before this Anchor
        CardCollection& playArea = player.getPlayArea();
        CardCollection& bank = player.getBank();

        // find the anchor's current position in the play area
        size_t anchorIndex = 0;
        for (; anchorIndex < playArea.size(); anchorIndex++) {
            if (playArea[anchorIndex].get() == this) {
                break;
            }
        }
        
        // move all cards to the bank (except this anchor)
        for (size_t i = 0; i < playArea.size();) {
            // move to bank if not self
            if (playArea[i].get() != this) {
                std::cout << "    " << playArea[i]->str() << " moved to bank." << std::endl;
                bank.push_back(std::move(playArea[i]));
                playArea.erase(playArea.begin() + i);
                // Don't increment i since we removed an element
            } else {
                // Skip this Anchor (Duh)
                i++;
            }
        }
    }
    else {
        // already played
    }
}

void Anchor::willAddToBank(Game& game, const Player& player) {

}