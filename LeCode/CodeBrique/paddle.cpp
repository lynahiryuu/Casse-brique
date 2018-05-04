#include "paddle.h"

Paddle::Paddle():Reflector()
{

}


void Paddle::Bounce(double x, double y, double speedX, double speedY){

}

void Paddle::GoLeft(){
    x_=x_-10;
}

void Paddle::GoRight(){
    x_=x_+10;
}
