#include "Player.h"
#include <map>

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
        if (card->type() == playAreaCard->type()) {
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

/*
    The general process is iterating through each card type through the CardType enum and then picking matching cards and then placing and sorting them before printing them in order
    time complexity be damned...
*/
void Player::displayBank() const {

    for (int suit = static_cast<int>(Card::CardType::Cannon); suit <= static_cast<int>(Card::CardType::Anchor); suit++) { // Converts the enum list into integers to iterate through
        
        CardCollection selectedSuit;

        for (const std::unique_ptr<Card>& card : bank) {

            if (static_cast<int>(card->type()) == suit) {
                selectedSuit.push_back(std::make_unique<Card>(*card)); // Dereference to get the card object
            }

        }

        if (!selectedSuit.empty()) {
            std::sort(selectedSuit.begin(), selectedSuit.end(), [](const std::unique_ptr<Card>& cardA, const std::unique_ptr<Card>& cardB) {
                return cardA->getValue() > cardB->getValue(); // Handy little lambda function
                });

            for (const std::unique_ptr<Card>& card : selectedSuit) {
                std::cout << card->str() << std::endl;
            }
        }

    }
}

/*
    Uses a map to identify the highest value card from each suit present in the bank
    Both sets the player's score and returns the total score
*/
int Player::calculateTotalScore() {
    std::map<Card::CardType, int> highestScores;

    for (const std::unique_ptr<Card>& card : bank) {
        
        Card::CardType suit = card->type();
        int cardValue = card->getValue();

        if (highestScores.find(suit) == highestScores.end()) { // Checking if the suit exists in the map yet
            highestScores[suit] = cardValue;
        }
        else {
            highestScores[suit] = std::max(highestScores[suit], cardValue);
        }

    }

    int totalScore = 0;

    for (const auto& pair : highestScores) {
        totalScore += pair.second;
    }

    score = totalScore;
    return totalScore;

}

int Player::getScore() const {
    return score;
}

std::string Player::getName() const {
    return name;
}

/*
    First plays the card into the play area and then checks if doing so causes a bust
    if not it plays the card and checks again if it causes a bust
*/
bool Player::playCard(std::unique_ptr<Card>& card, Game& game) {

    playArea.push_back(std::move(card)); // Play the card into the play area no matter what
    std::unique_ptr<Card>& movedCard = playArea.back();

    if (isBust(movedCard)) { // Does the card immediately cause a bust?
        return true;
    }

    // Else play the card
    movedCard->play(game, *this);

    if (isBust(movedCard)) { // Does playing the card cause a bust?
        return true;
    }

    return false;

}