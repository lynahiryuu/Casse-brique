#include "brick.h"

Brick::Brick(int x, int y):Reflector()
{
    x_=x;
    y_=y;
    heigth_=2;
    width_=5;
}

//Destructeur
Brick::~Brick(){
}

void Brick::Bounce(double ball_x,double ball_y,double speed_ball_X,double speed_ball_Y)
{
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

 // La brique est détruite
 delete this;
}


//Getters
int Brick::getX(){
    return x_;
}
int Brick::getY(){
    return y_;
}

//Setters

void Brick::setX(int x){
    x_=x;
}
void Brick::setY(int y){
    y_=y;
}
