#include "paddle.h"
#include "mainwindow.h"

Paddle::Paddle(double x, double y):Reflector()
{
 y_ = y;
 x_ = x;
 heigth_ = 2;
 width_ = 8;
 paddle_quadric_=gluNewQuadric();
}

Paddle::~Paddle(){
    gluDeleteQuadric(paddle_quadric_);
}

void Paddle::Bounce(double ball_x, double ball_y, double speed_ball_X, double speed_ball_Y){
    // La balle change cap :

    //Si la balle arrive du bas :
    if (ball_y <= y_)
    {
        speed_ball_Y = -speed_ball_Y;
    }
    //Si la balle arrive du haut :
    else if(ball_y >= y_)
    {
        speed_ball_Y = -speed_ball_Y;
    }
    //Si la balle arrive de gauche
    else if(ball_x <= x_)
    {
        speed_ball_X = -speed_ball_X;
    }
    //Si la balle arrive de droite
    else if(ball_x >= x_)
    {
        speed_ball_X = -speed_ball_X;
    }

}

void Paddle::Display() const{

}

void Paddle::setX(int x)
{
     x_ = x;
}
