#ifndef BALL_H
#define BALL_H
#include <typeinfo>
#include <GL/glu.h>


class Ball
{
public:
    Ball(double speedx, double speedy);
    ~Ball();
    void Move(const float timeInDays);
//    void BounceOn(Reflector* r);
    boolean Into(double x1, double y1, double x2, double y2);

    double getx_();
    double gety_();
    double getspeedx_() const;
    double getspeedy_() const;
    double getRadius_() const;

    void setx_(double x);
    void sety_(double y);
    void setspeedx_(double speedx);
    void setspeedy_(double speedy);
    void Display() const;
private:
    double radius_;
    double x_;
    double y_;
    double speedx_;
    double speedy_;
    GLUquadric *ball_quadric_;


   // double speedValue_;
   // double speedAngle_[];
};

#endif // BALL_H
