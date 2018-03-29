#ifndef PADDLE_H
#define PADDLE_H
#include "reflector.h"


class Paddle : public Reflector
{
public:
    Paddle();
private:
    double x_;
    double heigth_;
    double width_;
};

#endif // PADDLE_H
