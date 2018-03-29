#ifndef BALL_H
#define BALL_H
#include "reflector.h"
#include "wall.h"
#include "brick.h"
#include "paddle.h"
#include <typeinfo>
class Ball
{
public:
    Ball();
    void Move();
    void BounceOn(Reflector* r);

    double getx_();
    double gety_();
    double getspeedx_();
    double getspeedy_();

    void setx_(double x);
    void sety_(double y);
    void setspeedx_(double speedx);
    void setspeedy_(double speedy);
private:
    double radius_;
    double x_;
    double y_;
    double speedx_;
    double speedy_;

   // double speedValue_;
   // double speedAngle_[];
};

#endif // BALL_H
