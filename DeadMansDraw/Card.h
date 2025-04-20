#pragma once

/*
    Abstract card class as base for card types
*/

#include <string>
#include <memory>
#include <iostream>
#include <algorithm>

class Game;
class Player;

class Card {
public:

    enum class CardType {
        Cannon,
        Chest,
        Key,
        Sword,
        Hook,
        Oracle,
        Map,
        Mermaid,
        Kraken
    };

    virtual void play(Game& game, Player& player) = 0;
    virtual void willAddToBank(Game& game, const Player& player) = 0;
    virtual int getValue() const = 0;
    virtual std::string str() const = 0;
    virtual CardType Type() const = 0;

    virtual ~Card() = default;

private:

    int value = 0;
    // CardType(suit) will be immediately assigned on concrete card construction

};