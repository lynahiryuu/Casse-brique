#ifndef WALL_H
#define WALL_H
#include "reflector.h"
#include <GL/glu.h>


class Wall : public Reflector{
public:
    Wall(int id);
    ~Wall();
    void Bounce(double ball_x, double ball_y, double speed_ball_X, double speed_ball_Y) override;
    void Display() const;
private:
    int id_;
    GLUquadric *wall_quadric_;

    //bool destructor_;
};

#endif // WALL_H
