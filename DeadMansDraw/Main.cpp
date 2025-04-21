// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "gameTitle.h"
#include "Game.h"

int main()
{
    std::cout << GAME_TITLE << std::endl;
    Game game;
    game.startGame();
    return 0;
}
