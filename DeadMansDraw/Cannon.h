#pragma once

/*
    Cannon card type
*/

#include "Card.h"

class Cannon : public Card {
public:
    Cannon(int value);
    CardType type() const;
    std::string str() const;
    void play(Game& game, Player& player);
    void willAddToBank(Game& game, const Player& player);
    int getValue() const;

private:
    int value;
};