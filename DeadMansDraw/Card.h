#pragma once

/*
    Abstract card class as base for card types
*/

#include <string>
#include <memory>
#include <iostream>
#include <algorithm>
#include <vector>

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
        Kraken,
        Anchor
    };

    virtual void play(Game& game, Player& player) = 0;
    virtual void willAddToBank(Game& game, const Player& player) = 0;
    virtual int getValue() const = 0;
    virtual std::string str() const = 0;
    virtual CardType type() const = 0;

    virtual ~Card() = default;

protected:
    Card(CardType type) : cardType(type) {}
    int value = 0;
    CardType cardType;

};

typedef std::vector<std::unique_ptr<Card>> CardCollection; // All classes are going to include "Card.h" so this seems like a good spot to put it