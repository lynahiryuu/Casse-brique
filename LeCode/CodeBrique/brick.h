#ifndef BRICK_H
#define BRICK_H
#include "reflector.h"
#include <GL/glu.h>


class Brick : public Reflector
{
public:
    Brick(int x, int y);
    ~Brick();
    void Bounce(double ball_x, double ball_y, double speed_ball_X, double speed_ball_Y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    void Display() const;
private:
    int x_;
    int y_;
    double heigth_;
    double width_;
    GLUquadric *brick_quadric_;
};

#endif // BRICK_H
