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
    bool getDestructor();
    void setDestructor(bool destructor);
private:
    int id_;
    double weight_;
    double x_;
    double y_;
    bool destructor_;
};

#endif // WALL_H
