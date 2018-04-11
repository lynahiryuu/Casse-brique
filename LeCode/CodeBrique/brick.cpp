#include "brick.h"

Brick::Brick(int x, int y):Reflector()
{
    x_=x;
    y_=y;
    heigth_=2;
    width_=5;
}

void Brick::Bounce(double x,double y,double speedX,double speedY){

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
