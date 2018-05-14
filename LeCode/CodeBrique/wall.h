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
    int getId();
    void setId(int id);
private:
    int id_;
    float weight_;
    float x_;
    float y_;
    //GLUquadric *wall_quadric_;

    //bool destructor_;
};

#endif // WALL_H
