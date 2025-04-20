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

    if (sharedDeck.empty()) {
        return nullptr; // to be handled elsewhere, not my problem!
    }

    // Move the top card to a unique ptr
    std::unique_ptr<Card> drawnCard = std::move(sharedDeck.front());

    sharedDeck.erase(sharedDeck.begin());

    return drawnCard;
}

void Game::endTurn() {

    std::cout << "Bust! " << playerList[activePlayerIndex]->getName() << " loses all cards in play area." << std::endl;

    if (activePlayerIndex == playerList.size() - 1) {
        activePlayerIndex = 0;
    }
    else {
        activePlayerIndex += 1;
    }

}

void Game::discardHand(Player& player) {

    while (!player.getPlayArea().empty()) {
        discardPile.push_back(std::move(player.getPlayArea().back())); // Move ptrs to discard pile
        player.getPlayArea().pop_back(); // Clean up the remnant unique ptrs in the play area
    }

}

CardCollection createDeck() {

    // First loop for digits 2 through 7
    for (int value = 2; value <= 7; ++value) {

        // Iterate through each card type
        for (int type = static_cast<int>(Card::CardType::Cannon); type <= static_cast<int>(Card::CardType::Anchor); ++type) {

        }
    }

}