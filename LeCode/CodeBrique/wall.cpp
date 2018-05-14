#include "wall.h"
#include <iostream>
using namespace std;

Wall::Wall(int id):Reflector()
{
    id_ = id;
    cout<<id<<endl;
    cout<<getId()<<endl;
    //Si ce sont les murs de haut ou de bas alors weight = 30 sinon c'est 12
    if (id_ == 2 || id_ == 4 )
        weight_ = 30.0;
    else if(id_ == 1 || id_ == 3 )
        weight_ = 12.0;
    x_ = 0.0;
    y_ = 0.0;
    /*wall_quadric_= gluNewQuadric();
   glRotated(90,1,0,0);
   glTranslated(20,0,0);*/

    /* switch(id_){
   //Gauche
   case 1:
   {
       glRotated(90,1,0,0);
       break;
   }
   //Haut
   case 2:
   {
       glRotated(90,0,1,0);
       glTranslated(0,12,0);
       break;
   }
   //Droite
   case 3:
   {
       glRotated(90,1,0,0);
       glTranslated(30,0,0);
       break;
   }
   //Bas
   case 4:
   {
       glRotated(90,0,1,0);
       break;
   }
   default:
       cout<<"Mur impossible à créer"<<endl;
   }*/

}

Wall::~Wall(){
    //gluDeleteQuadric(wall_quadric_);
}
void Wall::Display()const{
cout<<"on est dans display"<<endl;
    /*int R_,V_,B_;
    R_=20;
    V_=20;
    B_=259;*/

    glPushMatrix();
    /*// Couleur de l'objet
    GLfloat colorAmbiante[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
    GLfloat colorDiffuse[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
    //GLfloat colorSpeculaire_planet[] = {0.5f, 0.5f, 0.5f, 1.0f};

    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbiante);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse);

    gluCylinder(wall_quadric_, 2, 2, 12.0, 50.0, 50.0);
    //gluSphere(wall_quadric_, 0.6, 50.0, 50.0);
    glPopMatrix();*/

    switch(id_)
    {
    //Gauche
    case 1:
    {
        cout<<"entré dans 1"<<endl;
        glRotated(90,0,0,1);
        glTranslated(-6.0,-14.8,0);
        //glPushMatrix();
        // Couleur de l'objet
        /*GLfloat colorAmbiante[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
            GLfloat colorDiffuse[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
            //GLfloat colorSpeculaire_planet[] = {0.5f, 0.5f, 0.5f, 1.0f};

            glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbiante);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse);

            gluCylinder(wall_quadric_, 0.2, 0.2, 12.0, 50.0, 50.0);*/


        break;
    }
        //Haut
    case 2:
    {
        cout<<"entré dans 2"<<endl;
        glRotated(0,0,0,1);
        glTranslated(-15.0,-11.0,0);
        //glTranslated(0,10.0,0);
        break;
    }
        //Droite
    case 3:
    {
        cout<<"entré dans 3"<<endl;
        glRotated(90,0,0,1);
        glTranslated(-6.0,14.8,0);
        break;
    }
        //Bas
    case 4:
    {
        cout<<"entré dans 4"<<endl;
        glTranslated(-15.0,11.0,0);
        //glRotated(45,0,0,1);
        //glTranslated(0,0,0);
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

void Wall::Bounce(double ball_x, double ball_y, double speed_ball_X, double speed_ball_Y){
    // La balle change cap :

    //Si la balle arrive du bas :
    if (ball_y >= 12)
    {
        speed_ball_Y = -speed_ball_Y;
    }
    //Si la balle arrive du haut :
    else if(ball_y <= 0)
    {
        //perdre une vie();
    }
    //Si la balle arrive de gauche
    else if(ball_x >= 30)
    {
        speed_ball_X = -speed_ball_X;
    }
    //Si la balle arrive de droite
    else if(ball_x <= 0)
    {
        speed_ball_X = -speed_ball_X;
    }
}

int Wall::getId(){
    return id_;
}

void Wall::setId(int id){
    id_ = id;
}

