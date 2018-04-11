#ifndef BRICK_H
#define BRICK_H
#include "reflector.h"


class Brick : public Reflector
{
public:
    Brick(int x, int y);
    virtual void Bounce();
    virtual int getX();
    virtual int getY();
    virtual void setX(int x);
    virtual void setY(int y);
private:
    int x_;
    int y_;
    double heigth_;
    double width_;
};

#endif // BRICK_H
