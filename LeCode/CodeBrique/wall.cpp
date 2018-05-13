#include "wall.h"
#include <iostream>
using namespace std;

Wall::Wall(int id):Reflector()
{
    //destructor_=destructor;
   int id_ = id;
   wall_quadric_=gluNewQuadric();

   switch(id_){
   //Gauche
   case 1: {
       glRotated(90,1,0,0);
       break;
   }
   //Haut
   case 2: {
       glRotated(90,0,1,0);
       glTranslated(0,12,0);
       break;
   }
   //Droite
   case 3: {
       glRotated(90,1,0,0);
       glTranslated(30,0,0);
       break;
   }
   //Bas
   case 4: {
       glRotated(90,0,1,0);
       break;
   }
   default:
       cout<<"Mur impossible à créer"<<endl;
   }

}

Wall::~Wall(){
    gluDeleteQuadric(wall_quadric_);
}
void Wall::Display()const{

    int R_,V_,B_;
    R_=250;
    V_=20;
    B_=89;

    glPushMatrix();
    // Couleur de l'objet
    //GLfloat colorAmbiante[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
    //GLfloat colorDiffuse[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
    //GLfloat colorSpeculaire_planet[] = {0.5f, 0.5f, 0.5f, 1.0f};

    //glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbiante);
    //glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse);
    //glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpeculaire_planet);


    // Affichage de la quadrique
    // ATTENTION CE SONT DES SPHERES ET PAS DES RECTANGLES
    //gluCylinder(brick_quadric_, 0.2, 0.2, 12.0, 50.0, 50.0);
    switch(id_)
    {
    //Gauche
    case 1:
    {
        // Couleur de l'objet
        GLfloat colorAmbiante[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
        GLfloat colorDiffuse[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
        //GLfloat colorSpeculaire_planet[] = {0.5f, 0.5f, 0.5f, 1.0f};

        glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbiante);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse);

        gluCylinder(wall_quadric_, 0.2, 0.2, 12.0, 50.0, 50.0);

        glPopMatrix();
        break;
    }
    //Haut
    case 2:
    {
        // Couleur de l'objet
        GLfloat colorAmbiante[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
        GLfloat colorDiffuse[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
        //GLfloat colorSpeculaire_planet[] = {0.5f, 0.5f, 0.5f, 1.0f};

        glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbiante);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse);

        gluCylinder(wall_quadric_, 0.2, 0.2, 30.0, 50.0, 50.0);

        glPopMatrix();
        break;
    }
        //Droite
    case 3:
    {
            // Couleur de l'objet
            GLfloat colorAmbiante[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
            GLfloat colorDiffuse[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
            //GLfloat colorSpeculaire_planet[] = {0.5f, 0.5f, 0.5f, 1.0f};

            glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbiante);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse);

            gluCylinder(wall_quadric_, 0.2, 0.2, 12.0, 50.0, 50.0);

            glPopMatrix();
            break;
        }
        //Gauche
    case 4:
    {
            // Couleur de l'objet
            GLfloat colorAmbiante[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
            GLfloat colorDiffuse[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
            //GLfloat colorSpeculaire_planet[] = {0.5f, 0.5f, 0.5f, 1.0f};

            glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbiante);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse);

            gluCylinder(wall_quadric_, 0.2, 0.2, 30.0, 50.0, 50.0);

            glPopMatrix();
            break;
        }
    default:{
        cout<<"Impossible d'afficher les quadriques"<<endl;
    }


}
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


// Getters
