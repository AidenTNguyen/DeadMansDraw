#pragma once

/*
    Responsible for overseeing the shared and discard decks, turns and initialising the cards, decks and players
*/

#include <string>
#include "Card.h"
#include "Player.h"

class Player;

using CardCollection = std::vector<std::unique_ptr<Card>>;

class Game {

public:

    Game();
    ~Game() = default;

    void startGame();
    void endGame();
    std::unique_ptr<Card> drawCard();
    void endTurn();
    void discardHand(Player& player);

private:

    int turnCount;
    CardCollection sharedDeck;
    CardCollection discardPile;
    std::vector<std::unique_ptr<Player>> playerList;
    int activePlayerIndex;

    void createDeck();
    std::unique_ptr<Card> createCard(const Card::CardType type, const int value) const;
    void shuffleDeck(CardCollection& cards);
    void initialisePlayers();

};
