#include "ball.h"
#include <string>
using namespace std;


Ball::Ball()
{
    radius_=0.5;
    setx_(8);
    sety_(8);
    setspeedx_(-0.1);
    setspeedy_(-0.1);
    ball_quadric_=gluNewQuadric();
}


Ball::~Ball(){
    gluDeleteQuadric(ball_quadric_);
}

//// Cette méthode permet de faire rebondir la balle en cas de collision et d'appeler la méthode qui fait changer de cap la balle
//void Ball::BounceOn(Reflector *r) {
//    string s=typeid(*r).name();
//    if(s=="Wall")
//    {
//        r->Bounce(x_, y_, speedx_, speedx_);
//    }
//    else if(s=="Paddle")
//    {
//        r->Bounce(x_, y_, speedx_, speedx_);
//    }
//    else if(s=="Brick")
//    {
//        r->Bounce(x_, y_, speedx_, speedx_);
//    }
//}

void Ball::Display() const{
    glPushMatrix();

    int R_,V_,B_;
    R_=15;
    V_=150;
    B_=89;
    glTranslated(x_+speedx_,y_+speedy_,0);

    // Couleur de l'objet
    GLfloat colorAmbiante[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
    GLfloat colorDiffuse[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
    //GLfloat colorSpeculaire_planet[] = {0.5f, 0.5f, 0.5f, 1.0f};

    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbiante);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse);
    //glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpeculaire_planet);


    // Affichage de la quadrique
    gluSphere(ball_quadric_, 0.5, 50.0, 50.0);


    glPopMatrix();}


void Ball::Move(const float timeInDays)
{
    setx_(getspeedx_()+getx_());
    sety_(getspeedy_()+gety_());
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

