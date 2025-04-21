#include "Game.h"
#include <iostream>
#include <random>
#include "CardFactory.h"

using namespace std;

void Game::startGame() {
    // Do gameplay loop while playAgain = true

    //do {

    //} while (playAgain);
}

void Game::endGame() {

    std::cout << "--- Game Over---" << std::endl;

    std::string victor;
    int highestScore = 0;

    for (const std::unique_ptr<Player>& player : playerList) {

        player->displayBank();
        std::cout << "| Score: " << player->getScore() << std::endl;

        if (player->getScore() > highestScore) {
            victor = player->getName();
            highestScore = player->getScore();

        }
    }

    std::cout << victor << " Wins!";
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

std::unique_ptr<Card> Game::createCard(const Card::CardType type, const int value) const {
    
    return instantiateCard(type, value);

}

void Game::createDeck() {

    // First loop for digits 2 through 7
    for (int value = 2; value <= 7; ++value) {

        // Iterate through each card type
        for (int type = static_cast<int>(Card::CardType::Cannon); type <= static_cast<int>(Card::CardType::Anchor); ++type) {

            sharedDeck.push_back(createCard(static_cast<Card::CardType>(type), value)); // Use the integer as an index of sorts fo the CardType enum list in Card.h

        }
    }
}

//void Game::shuffleDeck(CardCollection& cards) {
//    CardCollection shuffleDeck{ cards.begin(), cards.end() };
//    std::shuffle(shuffleDeck.begin(), shuffleDeck.end(), std::mt19937{ std::random_device{}() });
//    std::move(shuffleDeck.begin(), shuffleDeck.end(), cards.begin());
//}