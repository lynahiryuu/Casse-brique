#include "paddle.h"
#include "mainwindow.h"
#include "ball.h"

Paddle::Paddle(double x, double y):Reflector()
{
 x_ = x;
 y_ = y;
 heigth_ = 2;
 width_ = 8;
 direction_ =0;
 //paddle_quadric_=gluNewQuadric();
}

Paddle::~Paddle(){
    //gluDeleteQuadric(paddle_quadric_);
}

void Paddle::Bounce(Ball* b){
    // La balle change cap :

    float dist=0.1;// Taille de la zone de contact avec les briques
    float ballDiameter=0.5;
    //Si la balle arrive du bas :
    if (b->Into(x_+b->getRadius_(),y_-heigth_-b->getRadius_(),x_-width_-b->getRadius_(),y_-heigth_-b->getRadius_()-dist) )
    {
        b->setspeedy_(-b->getspeedy_());
    }
    //Si la balle arrive du haut :
    else if(b->Into(x_+b->getRadius_(),y_+b->getRadius_(),x_-width_-b->getRadius_(),y_+b->getRadius_()+dist))
    {
        b->setspeedy_(-b->getspeedy_());
    }
    //Si la balle arrive de gauche
    else if(b->Into(x_+b->getRadius_()+dist,y_+b->getRadius_(),x_+b->getRadius_(),y_-heigth_-b->getRadius_()))
    {
        b->setspeedx_(-b->getspeedx_());
    }
    //Si la balle arrive de droite
    else if(b->Into(x_-width_-b->getRadius_(),y_+b->getRadius_(),x_-width_-b->getRadius_()-dist,y_-heigth_-b->getRadius_()))
    {
        b->setspeedx_(-b->getspeedx_());
    }

}

void Paddle::Display() const{

    glPushMatrix();
    if (direction_ == -1 && x_ > -10){
        glTranslated(-1.0,0.0,0.0);
    }
    else if(direction_ == 1  && x_ < 10){
        glTranslated(1.0,0.0,0.0);
    }
// Affichage du paddle
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(x_,y_, -1.0f);
    glVertex3f(x_+5.0f, y_, -1.0f);
    glVertex3f(x_+5.0f, y_-1.0f, -1.0f);
    glVertex3f(x_, y_-1.0f, -1.0f);

    glColor3ub(255,0,0);
    glVertex3f(x_,y_, 1.0f);
    glVertex3f(x_+5.0f, y_, 1.0f);
    glVertex3f(x_+5.0f, y_-1.0f, 1.0f);
    glVertex3f(x_, y_-1.0f, 1.0f);

    glColor3ub(255,0,0);
    glVertex3f(x_,y_, 1.0f);
    glVertex3f(x_, y_, -1.0f);
    glVertex3f(x_, y_-1.0f, -1.0f);
    glVertex3f(x_, y_-1.0f, 1.0f);

    glColor3ub(255,0,0);
    glVertex3f(x_+5.0f,y_, 1.0f);
    glVertex3f(x_+5.0f, y_, -1.0f);
    glVertex3f(x_+5.0f, y_-1.0f, -1.0f);
    glVertex3f(x_+5.0f, y_-1.0f, 1.0f);

    glColor3ub(255,0,0);
    glVertex3f(x_, y_, 1.0f);
    glVertex3f(x_+5.0f, y_, 1.0f);
    glVertex3f(x_+5.0f, y_, -1.0f);
    glVertex3f(x_, y_, -1.0f);

    glColor3ub(255,0,0);
    glVertex3f(x_, y_-1.0f, 1.0f);
    glVertex3f(x_+5.0f, y_-1.0f, 1.0f);
    glVertex3f(x_+5.0f, y_-1.0f, -1.0f);
    glVertex3f(x_, y_-1.0f, -1.0f);

    glEnd();

    glPopMatrix();
}

void Paddle::setX(int x)
{
     x_ = x;
}

int Paddle::getX(){
    return x_;
}


void Paddle::movePaddle(int direction){
    if (direction == -1 && this->getX() > -10){
        direction_ = direction;
        this->setX(this->getX()-1);
        //glTranslated(-1,0.0,0.0);
    }
    else if(direction == 1 && this->getX() < 10){
        direction_ = direction;
        this->setX(this->getX()+1);
        //glTranslated(1,0.0,0.0);
    }
}
