#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;
class Player
{
public:
    Player(string name);
    int getHP();
    void setHP(int HP);
private:
    int score_;
    string name_;
    int HP_;


};

#endif // PLAYER_H
