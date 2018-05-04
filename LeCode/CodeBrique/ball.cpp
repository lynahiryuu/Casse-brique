#include "ball.h"
#include <string>
using namespace std;


Ball::Ball()
{
    radius_=3.14159;
    setx_(8);
    sety_(8);
    setspeedx_(3);
    setspeedy_(3);
}

// Cette méthode permet de faire rebondir la balle en cas de collision et d'appeler la méthode qui fait changer de cap la balle
void Ball::BounceOn(Reflector *r) {
    string s=typeid(*r).name();
    if(s=="Wall")
    {
        r->Bounce(x_, y_, speedx_, speedx_);
    }
    else if(s=="Paddle")
    {
        r->Bounce(x_, y_, speedx_, speedx_);
    }
    else if(s=="Brick")
    {
        r->Bounce(x_, y_, speedx_, speedx_);
    }
}




void Ball::Move()
{
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

