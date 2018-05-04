#ifndef REFLECTOR_H
#define REFLECTOR_H

class Reflector
{
public:
    Reflector();
    virtual void Bounce(double ball_x, double ball_y, double ball_speed_X, double ball_speed_Y)=0;
    virtual void Display()const =0;
};

#endif // REFLECTOR_H
