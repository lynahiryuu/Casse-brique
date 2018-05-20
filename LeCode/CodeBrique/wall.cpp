#include "wall.h"
#include <iostream>
#include "ball.h"
using namespace std;

Wall::Wall(int id):Reflector()
{
    id_ = id;
    //Attribut à false si la balle n'a pas touché le mur du bas
    destructor_ = false;

    //Si ce sont les murs de haut ou de bas alors weight = 30 sinon c'est 12
    if (id_ == 2 || id_ == 4 )
        weight_ = 30.0;
    else if(id_ == 1 || id_ == 3 )
        weight_ = 12.0;

    x_ = 0.0;
    y_ = 0.0;
}

Wall::~Wall(){

}

void Wall::Display()const{
    glPushMatrix();

    switch(id_)
    {
    //Gauche
    case 1:
    {
        //cout<<"entré dans 1"<<endl;
        glRotated(90,0,0,1);
        glTranslated(0.0,-14.8,0);
        break;
    }
        //Haut
    case 2:
    {
        //cout<<"entré dans 2"<<endl;
        glRotated(0,0,0,1);
        glTranslated(-15.0,-11.0,0);
        //glTranslated(0,10.0,0);
        break;
    }
        //Droite
    case 3:
    {
        //cout<<"entré dans 3"<<endl;
        glRotated(90,0,0,1);
        glTranslated(-12.0,14.8,0);
        break;
    }
        //Bas
    case 4:
    {
        //cout<<"entré dans 4"<<endl;
        glTranslated(-15.0,11.0,0);
        break;
    }
    default:{
        cout<<"Impossible d'afficher les murs"<<endl;
    }
    }

    glBegin(GL_QUADS);

    //Face arrière
    glColor3ub(255,0,0);
    glVertex3f(x_,y_, -1.0f);
    glVertex3f(x_+weight_, y_, -1.0f);
    glVertex3f(x_+weight_, y_-0.1f, -1.0f);
    glVertex3f(x_, y_-0.1f, -1.0f);

    //Face avant
    glColor3ub(255,0,0);
    glVertex3f(x_,y_, 1.0f);
    glVertex3f(x_+weight_, y_, 1.0f);
    glVertex3f(x_+weight_, y_-0.1f, 1.0f);
    glVertex3f(x_, y_-0.1f, 1.0f);

    //Face de gauche
    glColor3ub(255,0,0);
    glVertex3f(x_,y_, 1.0f);
    glVertex3f(x_, y_, -1.0f);
    glVertex3f(x_, y_-0.1f, -1.0f);
    glVertex3f(x_, y_-0.1f, 1.0f);

    //face de droite
    glColor3ub(255,0,0);
    glVertex3f(x_+weight_,y_, 1.0f);
    glVertex3f(x_+weight_, y_, -1.0f);
    glVertex3f(x_+weight_, y_-0.1f, -1.0f);
    glVertex3f(x_+weight_, y_-0.1f, 1.0f);

    //Face de haut
    glColor3ub(255,0,0);
    glVertex3f(x_, y_, 1.0f);
    glVertex3f(x_+weight_, y_, 1.0f);
    glVertex3f(x_+weight_, y_, -1.0f);
    glVertex3f(x_, y_, -1.0f);

    //Face de bas
    glColor3ub(255,0,0);
    glVertex3f(x_, y_-0.1f, 1.0f);
    glVertex3f(x_+weight_, y_-0.1f, 1.0f);
    glVertex3f(x_+weight_, y_-0.1f, -1.0f);
    glVertex3f(x_, y_-0.1f, -1.0f);

    glEnd();

    glPopMatrix();



}

void Wall::Bounce(Ball* b){
    // La balle change cap :

    // Mur Haut:
    if (b->gety_()>= 10)
    {
        //cout<<"haut"<<endl;

        b->setspeedy_(b->getspeedy_()*(-1));
    }
    // Mur Bas :
    else if(b->gety_() <= -10)
    {
        //cout<<"bas"<<endl;
        b->setspeedy_(b->getspeedy_()*(-1));
        destructor_ = true;

        //perdre une vie();
    }
    // Mur Droite
    if(b->getx_() >= 15)
    {
        //cout<<"droite"<<endl;

        b->setspeedx_(b->getspeedx_()*(-1));
    }
    // Mur Gauche :
    else if(b->getx_() <= -15)
    {
        //cout<<"gauche"<<endl;

        b->setspeedx_(b->getspeedx_()*(-1));

    }
}

int Wall::getId(){
    return id_;
}

void Wall::setId(int id){
    id_ = id;
}

bool Wall::getDestructor(){
    return destructor_;
}

void Wall::setDestructor(bool destructor){
    destructor_ = destructor;
}
