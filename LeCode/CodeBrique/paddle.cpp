#include "paddle.h"
#include "mainwindow.h"

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
