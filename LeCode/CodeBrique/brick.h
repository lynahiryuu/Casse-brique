#ifndef BRICK_H
#define BRICK_H
#include "reflector.h"


class Brick : public Reflector
{
public:
    Brick(int x, int y);
    void Bounce(double x,double y,double speedX,double speedY);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
private:
    int x_;
    int y_;
    double heigth_;
    double width_;
};

#endif // BRICK_H
