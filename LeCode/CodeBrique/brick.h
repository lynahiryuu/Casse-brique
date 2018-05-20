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
    void Bounce(Ball *b);
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
    bool destroy_;
    //GLUquadric *brick_quadric_;
};

#endif // BRICK_H
