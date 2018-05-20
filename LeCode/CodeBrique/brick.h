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
    Brick(float x, float y);
    ~Brick();
    void Bounce(Ball *b);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    void Display() const;
    int get_nb_broken_brick();
private:
    int nb_broken_brick_;
    GLfloat x_;
    GLfloat y_;
    double heigth_;
    double width_;
    QString imPath_;
    bool destroy_;

};

#endif // BRICK_H
