#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "brick.h"
#include "paddle.h"
#include "wall.h"
#include "ball.h"
#include "player.h"

class Model
{
public:
    Model();
    void StartNewGame();
private:
    //vector<Brick> *bricks;
    vector<Wall> *walls;
    Ball *ball_;
    Paddle *paddle_;
    Player *player_;
};

#endif // MODEL_H
