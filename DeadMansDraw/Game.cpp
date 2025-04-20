#include "Game.h"
#include <iostream>

using namespace std;

void Game::startGame() {
    // Do gameplay loop while playAgain = true

    //do {

    //} while (playAgain);
}

std::string Game::endGame() {

    std::cout << "--- Game Over---" << std::endl;

    std::unique_ptr<Player> victor = nullptr;

    for (const std::unique_ptr<Player>& player : playerList) {

        if (victor == nullptr || player->getScore() > victor->getScore()) {
            victor = std::make_unique<Player>(*player); // This copies instead of moves. The performance impact is HUGE! ENORMOUS!
        }

        player->displayBank();
        std::cout << "| Score: " << player->getScore() << std::endl;

        std::cout << player->getName() << " Wins!";

    }
}

std::unique_ptr<Card> Game::drawCard() {

}