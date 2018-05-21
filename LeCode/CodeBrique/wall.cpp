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

    // Affichage du mur selon son identifiant
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
    // La balle change de cap :

    // Mur Bas:
    if (b->gety_()>= 10)
    {
        //cout<<"bas"<<endl;

        //On indique que la balle est détruite
        b->set_destructed_(true);

        //La position est remontée pour éviter qu'elle ne retouche une seconde fois le mur du bas
        b->sety_(9);
        b->setx_(9);

        // La vitesse de la balle devient nulle pour éviter qu'elle ne se déplace
        b->setspeedx_(0);
        b->setspeedy_(0);

        //On indique qu'on a touché le mur du bas, permet d'enlever les points de vie dans la méthode LoseLife de Model
        destructor_ = true;

        //cout<<destructor_<<endl;
    }

    // Mur Haut : La balle rebondit

    else if(b->gety_() <= -10)
    {
        //cout<<"haut"<<endl;
        b->setspeedy_(b->getspeedy_()*(-1));
    }

    // Mur Droite : La balle rebondit
    if(b->getx_() >= 15)
    {
        //cout<<"droite"<<endl;

        b->setspeedx_(b->getspeedx_()*(-1));
    }
    // Mur Gauche : La balle rebondit
    else if(b->getx_() <= -15)
    {
        //cout<<"gauche"<<endl;

        b->setspeedx_(b->getspeedx_()*(-1));

    }
}

//Getters

int Wall::getId(){
    return id_;
}

bool Wall::getDestructor(){
    return destructor_;
}

//Setters

void Wall::setId(int id){
    id_ = id;
}

void Wall::setDestructor(bool destructor){
    destructor_ = destructor;
}
