#pragma once

/*
    Chest card type
*/

#include "Card.h"

class Chest : public Card {
public:
    Chest(int value);
    CardType type() const;
    std::string str() const;
    void play(Game& game, Player& player);
    void willAddToBank(Game& game, Player& player);
    int getValue() const;

private:
    int value;
};