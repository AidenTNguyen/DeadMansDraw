#pragma once

/*
    Mainly responsible for player's own play area and bank
    will hold both name and score
*/

#include <string>
#include "Card.h"

class Game;

using CardCollection = std::vector<Card*>;

class Player {
    
protected:

    int score;
    std::string name;

private:

    CardCollection playArea;
    CardCollection bank;
};