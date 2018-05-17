#ifndef BRICK_H
#define BRICK_H
#include "reflector.h"
#include <GL/glu.h>
#include <QString>
#include <QImage>
#include <QGLWidget>

class Brick : public Reflector
{
public:
    // Attention : le constructeur utilise des GLfloat en vrai
    Brick(float x, float y);
    ~Brick();
    void Bounce(double ball_x, double ball_y, double speed_ball_X, double speed_ball_Y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    void Display() const;
private:
    // Coordonnées du point en haut à gauche de la brique
    GLfloat x_;
    GLfloat y_;
    double heigth_;
    double width_;
    QString imPath_;
    //GLUquadric *brick_quadric_;
};

#endif // BRICK_H
