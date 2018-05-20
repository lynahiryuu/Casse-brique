#include "brick.h"


Brick::Brick(float x, float y ):Reflector()
{
    x_=x;
    y_=y;
    heigth_=1;
    width_=3;
    imPath_= ":/Textures/brick.png";
}

//Destructeur
Brick::~Brick(){
    //gluDeleteQuadric(brick_quadric_);
}



void Brick::Bounce(double ball_x,double ball_y,double speed_ball_X,double speed_ball_Y)
{
    // La balle change cap :

    float dist;
    float ballDiameter=0.5;
    //Si la balle arrive du bas :
    if (ball_y <= y_-(1-ballDiameter) && ball_y >= y_-(1-ballDiameter)-dist )
    {
        speed_ball_Y = -speed_ball_Y;
    }
    //Si la balle arrive du haut :
    else if(ball_y >= y_+ballDiameter && ball_y<= y_+ballDiameter +dist )
    {
        speed_ball_Y = -speed_ball_Y;
    }
    //Si la balle arrive de gauche
    else if(ball_x <= x_ - ballDiameter && ball_x <= x_ - ballDiameter - dist )
    {
        speed_ball_X = -speed_ball_X;
    }
    //Si la balle arrive de droite
    else if(ball_x >= x_)
    {
        speed_ball_X = -speed_ball_X;
    }

 // La brique est détruite
 delete this;
}


void Brick::Display() const{
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
    //gluSphere(brick_quadric_, 5, 50.0, 50.0);
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


//Getters
int Brick::getX(){
    return x_;
}
int Brick::getY(){
    return y_;
}

//Setters

void Brick::setX(int x){
    x_=x;
}
void Brick::setY(int y){
    y_=y;
}
