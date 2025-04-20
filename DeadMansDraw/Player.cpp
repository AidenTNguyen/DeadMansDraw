#include "Player.h"

Player::Player() : score(0)
{
    std::string names[] = { "Sam", "Jen", "Billy", "Bob", "Sally", "Joe", "Sue","Sasha", "Tina", "Marge" };
    name = names[rand() % 10];
}

/*
*  Determines if the given card matches suit with any cards in the current play area
*/
bool Player::isBust(std::unique_ptr<Card>& card) const {
    for (const std::unique_ptr<Card>& playAreaCard : playArea) {
        if (card->Type() == playAreaCard->Type()) {
            return true;
        }
        
        return false;
        
    }
}