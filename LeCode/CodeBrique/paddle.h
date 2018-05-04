#ifndef PADDLE_H
#define PADDLE_H
#include "reflector.h"


class Paddle : public Reflector
{
public:
    Paddle(double x, double y);
    void Bounce(double ball_x, double ball_y, double speed_ball_X, double speed_ball_Y);
    void setX(int x);

private:
    double x_;
    double y_;
    double heigth_;
    double width_;
};

#endif // PADDLE_H
