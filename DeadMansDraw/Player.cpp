#include "Player.h"

Player::Player() : score(0)
{
    std::string names[] = { "Sam", "Jen", "Billy", "Bob", "Sally", "Joe", "Sue","Sasha", "Tina", "Marge" };
    name = names[rand() % 10];
}

/*
*  Determines if the given card matches suit with any cards in the current play area
*/
bool Player::isBust(std::unique_ptr<Card>& card) const {
    for (const std::unique_ptr<Card>& playAreaCard : playArea) {
        if (card->Type() == playAreaCard->Type()) {
            return true;
        }
        
        return false;
        
    }
}

/*
    Moves the cards from the play area to the player's bank
*/
void Player::bankCards() {
    for (std::unique_ptr<Card>& card : playArea) {
        bank.push_back(std::move(card)); // Transferring ownership from Game -> Player
    }
    playArea.clear(); // say bye bye to nullptrs :D
}

CardCollection& Player::getPlayArea() {
    return playArea;
}

CardCollection& Player::getBank() {
    return bank;
}

void Player::displayPlayArea() const {
    for (const std::unique_ptr<Card>& card : playArea) {
        std::cout << card->str() << std::endl;
    }
}

void Player::displayBank() const {

    

    for (int suit = static_cast<int>(Card::CardType::Cannon); suit <= static_cast<int>(Card::CardType::Anchor); suit++) { // Converts the enum list into integers to iterate through
        
        CardCollection selectedSuit;

        for (const std::unique_ptr<Card>& card : bank) {

            if (static_cast<int>(card->Type()) == suit) {
                selectedSuit.push_back(std::make_unique<Card>(*card)); // Dereference to get the card object
            }

        }

        if (!selectedSuit.empty()) {
            std::sort(selectedSuit.begin(), selectedSuit.end(), [](const std::unique_ptr<Card>& cardA, const std::unique_ptr<Card>& cardB) {
                return cardA->getValue() > cardB->getValue();
            });
        }

    }
}