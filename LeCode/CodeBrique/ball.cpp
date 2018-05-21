#include "ball.h"
#include <string>
using namespace std;


Ball::Ball(double speedx, double speedy)
{
    radius_=0.5;
    setx_(0);
    sety_(3);
    setspeedx_(speedx);
    setspeedy_(speedy);
    ball_quadric_= gluNewQuadric();
    destructed_ = false;
    start_ = false;
}


Ball::~Ball(){
    gluDeleteQuadric(ball_quadric_);
}



void Ball::Display() const{        

    //Si la balle n'est pas détruite

    if (!destructed_){


        int R_,V_,B_;
        R_=0;
        V_=100;
        B_=100;
        glPushMatrix();
        glTranslated(x_+speedx_,y_+speedy_,0);

        // Couleur de l'objet

        GLfloat colorAmbiante[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
        GLfloat colorDiffuse[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
        //GLfloat colorSpeculaire_planet[] = {0.5f, 0.5f, 0.5f, 1.0f};

        glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbiante);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse);
        //glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpeculaire_planet);


        // Affichage de la quadrique
        gluSphere(ball_quadric_, radius_, 50.0, 50.0);


        glPopMatrix();
    }

    }


void Ball::Move()
{

   //Si la balle n'est pas détruite et si on autorise son mouvement en début de partie alors on changela position de la balle grâce à sa vitesse
    if (!destructed_ && start_){

        setx_(getspeedx_()+getx_());
        sety_(getspeedy_()+gety_());
    }
}

/*
 * Fonction pour indiquer si la balle est dans une zone rectangulaire
 *  entre les points(x1,y1) et (x2,y2)
 */

boolean Ball::Into(double x1, double y1, double x2, double y2){
    if(x_>x1 || x_<x2 || y_>y1 || y_<y2){
        return false;
    }
    else {
        return true;
    }
}


//Getters
double Ball::getx_(){
    return x_;
}
double Ball::gety_(){
    return y_;
}
double Ball::getspeedx_() const{
    return speedx_;
}
double Ball::getspeedy_() const{
    return speedy_;
}
double Ball::getRadius_() const{
    return radius_;
}

bool Ball::get_destructed_(){
    return destructed_;
}

bool Ball::get_start_(){
    return start_;
}

// Setters
void Ball::setx_(double x){
    x_=x;
}
void Ball::sety_(double y){
    y_=y;
}
void Ball::setspeedx_(double speedx){
    speedx_=speedx;
}
void Ball::setspeedy_(double speedy){
    speedy_=speedy;
}

void Ball::set_destructed_(bool destructed){
    destructed_ = destructed;
}

void Ball::set_start_(bool start){
    start_ = start;
}
