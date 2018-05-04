#ifndef WALL_H
#define WALL_H
#include "reflector.h"

class Wall : public Reflector{
public:
    Wall(int x, int y, int x2, int y2);
    void Bounce(double ball_x, double ball_y, double speed_ball_X, double speed_ball_Y) override;
private:
    double x1_;
    double y1_;
    double x2_;
    double y2_;
    //bool destructor_;
};

#endif // WALL_H
