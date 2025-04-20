#pragma once

/*
    Mainly responsible for player's own play area and bank
    will hold both name and score
*/

#include <string>
#include "Card.h"

class Player;

using CardCollection = std::vector<std::unique_ptr<Card>>;

class Game {

private:

    int turnCount;
    CardCollection sharedDeck;
    CardCollection discardPile;
    std::vector<std::unique_ptr<Player>> playerList; // Dont think this merits a typedef considering its used only once... i think... we'll see. Hope i dont forget to remove this
    std::unique_ptr<Player> activePlayer;

};
