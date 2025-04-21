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

    if (playArea.empty()) {
        return false;
    }

    for (const std::unique_ptr<Card>& playAreaCard : playArea) {

        if (card == playAreaCard) continue; // If its a duplicate which shouldnt happen skip over it

        if (card->type() == playAreaCard->type()) {
            std::cout << "Bust! " << name << " loses all cards in play area." << std::endl;
            return true;
        }
        
    }

    return false;
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

    std::cout << name << "'s Play Area:" << std::endl;

    for (const std::unique_ptr<Card>& card : playArea) {
        std::cout << card->str() << std::endl;
    }
}

/*
    The general process is iterating through each card type through the CardType enum and then picking matching cards and then placing and sorting them before printing them in order
    time complexity be damned...
*/
void Player::displayBank() {

    std::cout << name << "'s Bank:" << std::endl;

    for (int suit = static_cast<int>(Card::CardType::Cannon); suit <= static_cast<int>(Card::CardType::Anchor); suit++) { // Converts the enum list into integers to iterate through
        
        std::vector<const Card*> selectedSuit;

        for (const std::unique_ptr<Card>& card : bank) {

            if (static_cast<int>(card->type()) == suit) {
                selectedSuit.push_back(card.get());
            }

        }

        if (!selectedSuit.empty()) {
            std::sort(selectedSuit.begin(), selectedSuit.end(), [](const Card* cardA, const Card* cardB) {
                return cardA->getValue() > cardB->getValue(); // Handy little lambda function
                });

            for (const Card* card : selectedSuit) {
                std::cout << "  " << card->str() << " ";
            }
            std::cout << std::endl;
        }

    }

    std::cout << "| Score: " << calculateTotalScore() << std::endl;
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
* This function will be responsible for checking if the drawn card results in a bust
*/
bool Player::playCard(std::unique_ptr<Card> card, Game& game) {
    std::cout << name << " draws a " << card->str() << std::endl;

    // Check for bust before playing
    if (isBust(card)) {
        playArea.push_back(std::move(card));
        setBusted(true);
        return true;
    }

    // Store the card type before moving it
    Card::CardType cardType = card->type();

    // Move the card to play area
    playArea.push_back(std::move(card));

    // Play the card's effect - this might modify the play area!
    size_t cardIndex = playArea.size() - 1;
    playArea[cardIndex]->play(game, *this);

    for (size_t i = 0; i < playArea.size(); i++) {
        for (size_t j = i + 1; j < playArea.size(); j++) {
            if (playArea[i] && playArea[j] &&
                playArea[i]->type() == playArea[j]->type()) {
                setBusted(true);
                return true;
            }
        }
    }

    return false;
}

void Player::setBusted(bool state) {
    busted = state;
}

bool Player::hasBusted() const {
    return busted;
}