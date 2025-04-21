#pragma once

/*
    Mainly responsible for player's own play area and bank
    will hold both name and score
*/

#include <string>
#include "Card.h"

class Game;

using CardCollection = std::vector<std::unique_ptr<Card>>;

class Player {

public:

    Player();
    ~Player() = default;

    bool isBust(std::unique_ptr<Card>& card) const;
    void bankCards();
    CardCollection& getPlayArea();
    CardCollection& getBank();
    void displayPlayArea() const;
    void displayBank();
    int calculateTotalScore();
    int getScore() const;
    std::string getName() const;
    bool playCard(std::unique_ptr<Card> card, Game& game);
    void setBusted(bool state);
    bool hasBusted() const;
    
protected:

    int score;
    std::string name;
    bool busted = false;

private:

    CardCollection playArea;
    CardCollection bank;
};