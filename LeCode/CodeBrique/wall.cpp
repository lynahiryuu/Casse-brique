#include "wall.h"

Wall::Wall(int x, int y, int x2, int y2):Reflector()
{
    //destructor_=destructor;
    x1_=x;
    x2_= x2;
    y1_=y;
    y2_= y2;

}


void Wall::Bounce(double ball_x, double ball_y, double speed_ball_X, double speed_ball_Y){
    // La balle change cap :

    //Si la balle arrive du bas :
    if (ball_y <= y1_)
    {
        speed_ball_Y = -speed_ball_Y;
    }
    //Si la balle arrive du haut :
    else if(ball_y >= y1_)
    {
        //perdre une vie();
    }
    //Si la balle arrive de gauche
    else if(ball_x <= x1_)
    {
        speed_ball_X = -speed_ball_X;
    }
    //Si la balle arrive de droite
    else if(ball_x >= x1_)
    {
        speed_ball_X = -speed_ball_X;
    }
}


// Getters
