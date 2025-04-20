#pragma once

/*
    Mainly responsible for player's own play area and bank
    will hold both name and score
*/

#include <string>
#include "Card.h"

class Game;

class Player {
    
protected:

    int score;
    std::string name;

private:

    Card playArea;
};