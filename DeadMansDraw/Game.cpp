#include "Game.h"
#include <iostream>
#include <random>
#include "CardFactory.h"

using namespace std;

Game::Game() {

}

void Game::startGame() {

    initialisePlayers();
    createDeck();
    shuffleDeck(sharedDeck);

    // Some local variables


    std::cout << "Starting Dead Man's Draw++!" << std::endl;

    int round = 1;
    int currentTurn = 1;
    bool newRound = true;
    bool playAgain = false;

    while (round != 21 && !sharedDeck.empty()) {

        std::unique_ptr<Player>& activePlayer = playerList[activePlayerIndex];

        std::cout << "--- Round " << round << ", Turn " << currentTurn << " ---" << std::endl;
        std::cout << activePlayer->getName() << "'s turn: " << std::endl;
        activePlayer->displayBank();

        do {

            auto drawnCard = drawCard();
            activePlayer->playCard(std::move(drawnCard), *this);

            if (activePlayer->hasBusted()) {
                discardHand(activePlayer);
                endTurn();
                playAgain = false;
                break;
            }

            activePlayer->displayPlayArea();

            std::string reply;
            std::cout << std::endl;
            std::cout << "Draw again ? (y/n): ";
            std::getline(std::cin, reply);

            if (reply == "y") {
                playAgain = true;
            }
            else {
                activePlayer->bankCards(*this);
                activePlayer->displayBank();
                playAgain = false;
                currentTurn++;

                newRound = !newRound; // This method would not work for more than 2 players

                if (newRound) {
                    round++;
                }

                endTurn();
            }

            } while (playAgain);
        }

    endGame();
}

void Game::endGame() {

    std::cout << "--- Game Over---" << std::endl;

    std::string victor;
    int highestScore = 0;

    for (const std::unique_ptr<Player>& player : playerList) {

        player->displayBank();
        std::cout << "| Score: " << player->calculateTotalScore() << std::endl;

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

    playerList[activePlayerIndex]->setBusted(false);

    if (activePlayerIndex == playerList.size() - 1) {
        activePlayerIndex = 0;
    }
    else {
        activePlayerIndex += 1;
    }

}

// Some cool dual action discarding going on here. The hip and pop new stuff for the anchor cards and the regular stuff for the muggles.
void Game::discardHand(std::unique_ptr<Player>& player) {

    bool anchorInPlay = false;
    size_t anchorIndex = 0;

    for (size_t index = 0; index < player->getPlayArea().size(); index++ {

    }




    while (!player->getPlayArea().empty()) {
        discardPile.push_back(std::move(player->getPlayArea().back())); // Move ptrs to discard pile
        player->getPlayArea().pop_back(); // Clean up the remnant unique ptrs in the play area
    }

}

// Uses the CardFactory
std::unique_ptr<Card> Game::createCard(const Card::CardType type, const int value) const {
    
    return instantiateCard(type, value);

}

void Game::createDeck() {

    // First loop for digits 2 through 7
    for (int value = 2; value <= 7; ++value) {

        // Iterate through each card type
        for (int type = static_cast<int>(Card::CardType::Cannon); type <= static_cast<int>(Card::CardType::Anchor); ++type) {

            if (type == static_cast<int>(Card::CardType::Mermaid)) {
                sharedDeck.push_back(createCard(static_cast<Card::CardType>(type), value + 2));
            }
            else {
                sharedDeck.push_back(createCard(static_cast<Card::CardType>(type), value)); // Use the integer as an index of sorts fo the CardType enum list in Card.h
            }
        }
    }
}

void Game::shuffleDeck(CardCollection& cards) {
    CardCollection shuffleDeck{ std::make_move_iterator(cards.begin()), std::make_move_iterator(cards.end()) };
    std::shuffle(shuffleDeck.begin(), shuffleDeck.end(), std::mt19937{ std::random_device{}() });
    std::move(shuffleDeck.begin(), shuffleDeck.end(), cards.begin());
}

// If the game was more than 2 people this function would take an integer for no. players
void Game::initialisePlayers() {
    activePlayerIndex = 0;

    playerList.push_back(std::make_unique<Player>());
    playerList.push_back(std::make_unique<Player>());
}

CardCollection& Game::getSharedDeck() {
    return sharedDeck;
}

CardCollection& Game::getDiscardPile() {
    return discardPile;
}

std::vector<std::unique_ptr<Player>>& Game::getPlayerList() {
    return playerList;
}