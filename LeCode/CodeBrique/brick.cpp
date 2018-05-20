#include "brick.h"

#include "ball.h"
#include <iostream>

using namespace std;

Brick::Brick(float x, float y ):Reflector()
{
    x_=x;
    y_=y;
    heigth_=1;
    width_=3;
    imPath_= ":/Textures/brick.png";
    destroy_=false;
    nb_broken_brick_=0;
}

//Destructeur
Brick::~Brick(){

}



void Brick::Bounce(Ball* b)
{ if(!destroy_){
    float dist=0.1;// Taille de la zone de contact avec les briques
    float ballDiameter=0.5;
    //Si la balle arrive du bas :
    if (b->Into(x_+width_,y_+dist+b->getRadius_(),x_,y_))
    {
        //cout<<"brickBas"<<x_<<"###"<<y_<<endl;
        b->setspeedy_(-b->getspeedy_());
        destroy_=true;
        nb_broken_brick_ += 1;
    }
    //Si la balle arrive du haut :
    else if(b->Into(x_+width_,y_-heigth_,x_,y_-heigth_-dist-b->getRadius_()))
    {
        //cout<<"brickHaut"<<x_<<"###"<<y_<<endl;
        b->setspeedy_(-b->getspeedy_());
        destroy_=true;
        nb_broken_brick_ += 1;

    }
    //Si la balle arrive de gauche
    else if(b->Into(x_+b->getRadius_()+dist,y_,x_+b->getRadius_(),y_-heigth_))
    {
        //cout<<"brickGauche"<<x_<<"###"<<y_<<endl;
        b->setspeedx_(-b->getspeedx_());
        destroy_=true;
        nb_broken_brick_ += 1;

    }
    //Si la balle arrive de droite
    else if(b->Into(x_-b->getRadius_(),y_,x_+width_-b->getRadius_()-dist,y_-heigth_))
    {
        //cout<<"brickDroite"<<x_<<"###"<<y_<<endl;
        b->setspeedx_(-b->getspeedx_());
        destroy_=true;
        nb_broken_brick_ += 1;

    }
}

}


void Brick::Display() const{
    if(!destroy_){

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(x_,y_, -1.0f);
    glVertex3f(x_+3.0f, y_, -1.0f);
    glVertex3f(x_+3.0f, y_-1.0f, -1.0f);
    glVertex3f(x_, y_-1.0f, -1.0f);

    glColor3ub(255,0,0);
    glVertex3f(x_,y_, 1.0f);
    glVertex3f(x_+3.0f, y_, 1.0f);
    glVertex3f(x_+3.0f, y_-1.0f, 1.0f);
    glVertex3f(x_, y_-1.0f, 1.0f);

    glColor3ub(255,0,0);
    glVertex3f(x_,y_, 1.0f);
    glVertex3f(x_, y_, -1.0f);
    glVertex3f(x_, y_-1.0f, -1.0f);
    glVertex3f(x_, y_-1.0f, 1.0f);

    glColor3ub(255,0,0);
    glVertex3f(x_+3.0f,y_, 1.0f);
    glVertex3f(x_+3.0f, y_, -1.0f);
    glVertex3f(x_+3.0f, y_-1.0f, -1.0f);
    glVertex3f(x_+3.0f, y_-1.0f, 1.0f);

    glColor3ub(255,0,0);
    glVertex3f(x_, y_, 1.0f);
    glVertex3f(x_+3.0f, y_, 1.0f);
    glVertex3f(x_+3.0f, y_, -1.0f);
    glVertex3f(x_, y_, -1.0f);

    glColor3ub(255,0,0);
    glVertex3f(x_, y_-1.0f, 1.0f);
    glVertex3f(x_+3.0f, y_-1.0f, 1.0f);
    glVertex3f(x_+3.0f, y_-1.0f, -1.0f);
    glVertex3f(x_, y_-1.0f, -1.0f);

    glEnd();
    // Matrice de translation

    glPopMatrix();
    }
}


//Getters
int Brick::getX(){
    return x_;
}
int Brick::getY(){
    return y_;
}

int Brick::get_nb_broken_brick(){
    return nb_broken_brick_;
}

//Setters

void Brick::setX(int x){
    x_=x;
}
void Brick::setY(int y){
    y_=y;
}
