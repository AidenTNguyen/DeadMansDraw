#pragma once

/*
    Cannon card type
*/

#include "Card.h"

class Cannon : public Card {
public:
    Cannon(int value);

private:
    int value;
};