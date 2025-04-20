#pragma once

/*
    Anchor card type
*/

#include "Card.h"

class Anchor : public Card {
public:
    Anchor(int value);
    CardType type() const;
    std::string str() const;
    void play(Game& game, Player& player);
    void willAddToBank(Game& game, const Player& player);
    int getValue() const;

private:
    int value;
    bool played;
};