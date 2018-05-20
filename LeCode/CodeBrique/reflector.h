#ifndef REFLECTOR_H
#define REFLECTOR_H
#include "ball.h"


class Reflector
{
public:
    Reflector();
    virtual void Bounce(Ball* b)=0;
    virtual void Display()const =0;
};

#endif // REFLECTOR_H
