#include "Mermaid.h"

using namespace std;

Mermaid::Mermaid(int _value)
    : Card(CardType::Mermaid), value(_value)
{
}

int Mermaid::getValue() const {
    return value;
}

Card::CardType Mermaid::type() const {
    return cardType;
}

std::string Mermaid::str() const {
    return "Mermaid(" + std::to_string(getValue()) + ")";
}

void Mermaid::play(Game& game, Player& player) {

}

void Mermaid::willAddToBank(Game& game, const Player& player) {

}