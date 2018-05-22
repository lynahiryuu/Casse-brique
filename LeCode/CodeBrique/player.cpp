#include "player.h"

Player::Player(string name)
{
 HP_ = 3;
 name_ = name;
 score_ = 0;
}


// Getters

int Player::getHP()
{
 return HP_;
}

int Player::getScore(){
    return score_;
}
// Setters
void Player::setHP(int HP)
{
    HP_ = HP;
}

void Player::setScore(int score){
    score_=score;
}
