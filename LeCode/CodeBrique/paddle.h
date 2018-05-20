#ifndef PADDLE_H
#define PADDLE_H
#include "reflector.h"
#include <GL/glu.h>



class Paddle : public Reflector{
public:
    Paddle(double x, double y);
    ~Paddle();
    void Bounce(Ball *b);
    void setX(int x);
    void Display() const;
    int getX();
    void movePaddle(int direction);


private:
    double x_;
    double y_;
    double heigth_;
    double width_;
    int direction_;
    //GLUquadric *paddle_quadric_;

};

#endif // PADDLE_H
