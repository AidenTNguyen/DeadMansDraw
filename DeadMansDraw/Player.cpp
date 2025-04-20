#include "Player.h"

Player::Player() : score(0)
{
    std::string names[] = { "Sam", "Jen", "Billy", "Bob", "Sally", "Joe", "Sue","Sasha", "Tina", "Marge" };
    name = names[rand() % 10];
}