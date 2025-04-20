// CardFactory.h
#include "Card.h"

std::unique_ptr<Card> createCard(Card::CardType type, int value);