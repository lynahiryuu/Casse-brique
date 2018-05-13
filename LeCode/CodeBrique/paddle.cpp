#include "paddle.h"
#include "mainwindow.h"

Paddle::Paddle(double x, double y):Reflector()
{
 y_ = y;
 x_ = x;
 heigth_ = 2;
 width_ = 8;
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
    // Couleur de l'objet
    //GLfloat colorAmbiante[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
    //GLfloat colorDiffuse[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
    //GLfloat colorSpeculaire_planet[] = {0.5f, 0.5f, 0.5f, 1.0f};

    //glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbiante);
    //glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse);
    //glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpeculaire_planet);


    // Affichage de la quadrique
    // ATTENTION CE SONT DES SPHERES ET PAS DES RECTANGLES
    //gluSphere(brick_quadric_, 5, 50.0, 50.0);
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


    glPopMatrix();
}

void Paddle::setX(int x)
{
     x_ = x;
}
