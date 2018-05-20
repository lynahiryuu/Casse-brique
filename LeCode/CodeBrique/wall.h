#ifndef WALL_H
#define WALL_H
#include "reflector.h"
#include <GL/glu.h>


class Wall : public Reflector{
public:
    Wall(int id);
    ~Wall();
    void Bounce(Ball *b) ;
    void Display() const;
    int getId();
    void setId(int id);
private:
    int id_;
    double weight_;
    double x_;
    double y_;
    //GLUquadric *wall_quadric_;

    //bool destructor_;
};

#endif // WALL_H
