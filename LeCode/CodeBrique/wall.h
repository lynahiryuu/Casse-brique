#ifndef WALL_H
#define WALL_H
#include "reflector.h"

class Wall : public Reflector{
public:
    Wall(bool destructor);
    void Bounce(double x,double y,double speedX,double speedY);
private:
    double x1_;
    double y1_;
    double x2_;
    double y2_;
    bool destructor_;
};

#endif // WALL_H
