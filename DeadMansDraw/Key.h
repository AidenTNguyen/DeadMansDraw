#pragma once

/*
    Key card type
    Essentially redundant as chest will be the one checking for key presence in the play area
*/

#include "Card.h"

class Key : public Card {
public:
    Key(int value);
    CardType type() const;
    std::string str() const;
    void play(Game& game, Player& player);
    void willAddToBank(Game& game, const Player& player);
    int getValue() const;

private:
    int value;
};