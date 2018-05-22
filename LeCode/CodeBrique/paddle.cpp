#include "paddle.h"

#include "mainwindow.h"
#include "ball.h"
#include <iostream>

using namespace std;

Paddle::Paddle(double x, double y):Reflector()
{
 x_ = x-2.5;
 y_ = y;
 heigth_ = 1;
 width_ = 5;
 direction_ =0;
}

Paddle::~Paddle(){
}

void Paddle::Bounce(Ball* b){

    //Vitesse totale de la balle
    double totalSpeed=abs(b->getspeedx_())+abs(b->getspeedy_());
    // La balle change cap :

    float dist=0.05;// Taille de la zone de contact avec le paddle

    //Si la balle arrive du haut alors elle change de direction
    if(b->Into(x_+width_,y_-heigth_,x_,y_-heigth_-dist-b->getRadius_()))
    {
        //cout<<"PADDLE"<<endl;
        double distToRight=(b->getx_()-x_)/(width_);
        b->setspeedy_(-totalSpeed*(abs(0.5-distToRight)));
        b->setspeedx_(-totalSpeed-b->getspeedy_());
    }

}

void Paddle::Display() const{

    //Translation du palet dans l'interface graphique
    glPushMatrix();
    if (direction_ == -1 && x_ > -15){
        glTranslated(-1,0.0,0.0);
    }
    else if(direction_ == 1  && x_ < 15-width_){
        glTranslated(1,0.0,0.0);
    }

    // Affichage du palet
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

//Setter

void Paddle::setX(double x)
{
     x_ = x;
}


//Getter

double Paddle::getX(){
    return x_;
}


void Paddle::movePaddle(int direction){

    //Si la direction indique la droite et si le palet ne dépasse pas de la fenêtre alors déplacement de 1 vers la droite
    if (direction == -1 && this->getX() > -15){

        direction_ = direction;
        this->setX(this->getX()-1);

    }

    //Si la direction indique la gauche et si le palet ne dépasse pas de la fenêtre alors déplacement de 1 vers la gauche
    else if(direction == 1 && this->getX() < 15-width_){

        direction_ = direction;
        this->setX(this->getX()+1);

    }
}
