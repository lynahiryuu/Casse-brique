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
    hit_=false;
}

//Destructeur
Brick::~Brick(){

}



void Brick::Bounce(Ball* b)
{
    //Si la brique n'est pas détruite alors on l'affiche
    if(!destroy_){
        float dist=0.1;// Taille de la zone de contact avec les briques

        //Si la balle arrive du bas :
        if (b->Into(x_+width_,y_+dist+b->getRadius_(),x_,y_))
        {
            //cout<<"brickBas"<<x_<<"###"<<y_<<endl;
            hit_=true;

            //La balle change de direction, on indique que la brique est détruite et on augmente le nombre de briques brisées
            b->setspeedy_(-b->getspeedy_());
            destroy_=true;
            nb_broken_brick_ += 1;
        }
        //Si la balle arrive du haut :
        else if(b->Into(x_+width_,y_-heigth_-dist-b->getRadius_(),x_,y_-heigth_))
        {
            //cout<<"brickHaut"<<x_<<"###"<<y_<<endl;
            hit_=true;

            //La balle change de direction, on indique que la brique est détruite et on augmente le nombre de briques brisées
            b->setspeedy_(-b->getspeedy_());
            destroy_=true;
            nb_broken_brick_ += 1;

        }
        //Si la balle arrive de gauche
        else if(b->Into(x_+b->getRadius_()+dist+width_,y_,x_+width_,y_-heigth_))
        {
            //cout<<"brickGauche"<<x_<<"###"<<y_<<endl;
            hit_=true;

            //La balle change de direction, on indique que la brique est détruite et on augmente le nombre de briques brisées

            b->setspeedx_(-b->getspeedx_());
            destroy_=true;
            nb_broken_brick_ += 1;

        }
        //Si la balle arrive de droite
        else if(b->Into(x_,y_,x_-b->getRadius_()-dist,y_-heigth_))
        {
            //cout<<"brickDroite"<<x_<<"###"<<y_<<endl;
            hit_=true;

            //La balle change de direction, on indique que la brique est détruite et on augmente le nombre de briques brisées

            b->setspeedx_(-b->getspeedx_());
            destroy_=true;
            nb_broken_brick_ += 1;

        }
    }

}


void Brick::Display() const{

    //Si la brique n'est pas détruite alors on l'affiche
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

bool Brick::getHit(){
    return hit_;
}

//Setters

void Brick::setX(int x){
    x_=x;
}
void Brick::setY(int y){
    y_=y;
}
void Brick::setHit(bool b){
    hit_=b;
}
