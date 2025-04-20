// CardFactory.h
#include "Card.h"

std::unique_ptr<Card> instantiateCard(Card::CardType type, int value);