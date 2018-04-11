#ifndef REFLECTOR_H
#define REFLECTOR_H


class Reflector
{
public:
    Reflector();
    virtual void Bounce(double x,double y,double speedX,double speedY)=0;
};

#endif // REFLECTOR_H
