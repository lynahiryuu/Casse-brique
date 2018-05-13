#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "brick.h"
#include "paddle.h"
#include "wall.h"
#include "ball.h"
#include "player.h"
#include "mainwindow.h"



class Model
{
public:
    Model();
    void StartNewGame();
    void LoseLife();
    bool LoseGame();
    bool WinGame();
    int get_H_Wid();
    int get_W_Wid();
    void Display() const;
    void update();
    void setDirectionPaddle(int direction);

private:
    vector<Brick *> bricks_;
    vector<Wall *> walls_;
    Ball *ball_;
    Paddle *paddle_;
    Player *player_;
    MainWindow *main_;
    int width_W_;
    int height_W_;
    int direction_paddle_;
};

#endif // MODEL_H
