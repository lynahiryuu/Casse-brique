#ifndef PADDLE_H
#define PADDLE_H
#include "reflector.h"
#include <GL/glu.h>



class Paddle : public Reflector{
public:
    Paddle(double x, double y);
    ~Paddle();
    void Bounce(Ball *b);
    void setX(double x);
    void Display() const;
    double getX();
    void movePaddle(int direction);


private:
    // Enregistre la coordonnée du point en bas à droite du paddle
    double x_;
    double y_;
    double heigth_;
    double width_;
    int direction_;
    //GLUquadric *paddle_quadric_;

};

#endif // PADDLE_H
