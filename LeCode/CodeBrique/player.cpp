#include "player.h"

Player::Player(string name)
{
 HP_ = 3;
 name_ = name;
 score_ = 0;
}

int Player::getHP()
{
 return HP_;
}
void Player::setHP(int HP)
{
    HP_ = HP;
}
