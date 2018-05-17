#include "ball.h"
#include <string>
using namespace std;


Ball::Ball()
{
    radius_=3.14159;
    setx_(8);
    sety_(8);
    setspeedx_(3);
    setspeedy_(3);
    ball_quadric_=gluNewQuadric();
}


Ball::~Ball(){
    gluDeleteQuadric(ball_quadric_);
}

// Cette méthode permet de faire rebondir la balle en cas de collision et d'appeler la méthode qui fait changer de cap la balle
void Ball::BounceOn(Reflector *r) {
    string s=typeid(*r).name();
    if(s=="Wall")
    {
        r->Bounce(x_, y_, speedx_, speedx_);
    }
    else if(s=="Paddle")
    {
        r->Bounce(x_, y_, speedx_, speedx_);
    }
    else if(s=="Brick")
    {
        r->Bounce(x_, y_, speedx_, speedx_);
    }
}

void Ball::Display() const{
    int R_,V_,B_;
    R_=250;
    V_=20;
    B_=89;
    glPushMatrix();
    // Déplacement de la balle
    glTranslated(this->getspeedx_(),this->getspeedy_(),0);
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


void Ball::Move()
{
    setx_(getspeedx_()+getx_());
    sety_(getspeedy_()+gety_());
//    glTranslated(getspeedx_(),getspeedy_(),0);
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

