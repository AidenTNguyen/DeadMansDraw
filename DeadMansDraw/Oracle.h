#pragma once

/*
    Oracle card type
*/

#include "Card.h"

class Oracle : public Card {
public:
    Oracle(int value);
    CardType type() const;
    std::string str() const;
    void play(Game& game, Player& player);
    void willAddToBank(Game& game, const Player& player);
    int getValue() const;

private:
    int value;
};