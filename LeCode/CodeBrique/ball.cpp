#include "ball.h"
#include <string>
using namespace std;


Ball::Ball()
{


    radius_=3.14;
    setx_(8);
    sety_(8);
    setspeedx_(3);
    setspeedy_(3);
}

void Ball::BounceOn(Reflector *r) {
    string s=typeid(*r).name();
    if(s=="Wall"){
    }
    else if(s=="Paddle"){

    }
    else if(s=="Brick"){

    }
    else{
        //Error
    }
}




void Ball::Move(){
    setx_(getspeedx_()+getx_());
    sety_(getspeedy_()+gety_());
}


//Getters
double Ball::getx_(){
    return x_;
}
double Ball::gety_(){
    return y_;
}
double Ball::getspeedx_(){
    return speedx_;
}
double Ball::getspeedy_(){
    return speedy_;
}

// Setters
void Ball::setx_(double x){
    x_=x;
}
void Ball::sety_(double y){
    y_=y;
}
void Ball::setspeedx_(double speedx){
    speedx_=speedx;
}
void Ball::setspeedy_(double speedy){
    speedy_=speedy;
}

