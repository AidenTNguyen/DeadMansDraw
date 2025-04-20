#pragma once

/*
    Abstract card class as base for card types
*/

#include <iostream>

class Game;
class Player;

class Card {
public:
    virtual void play(Game& game, Player& player) = 0;
    virtual void willAddToBank(Game& game, Player& player) = 0;
    virtual int getValue() const = 0;
    virtual std::string str() const = 0;
    virtual CardType Type() const = 0;

};