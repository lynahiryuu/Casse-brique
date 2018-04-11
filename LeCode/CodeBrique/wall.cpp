#include "wall.h"

Wall::Wall(bool destructor):Reflector()
{
    destructor_=destructor;
    x1_=1;
    x2_=1;
    y1_=1;
    y2_=1;

}

void Wall::Bounce(double x, double y, double speedX,double speedY){
    // On suppose que l'origine est en bas à gauche.
    if( (y1_ >y) && (y2_>y)){
        //Mur du haut
    }
    else if(x1_<x){
        //Mur de gauche
    }
    else if(x2_>x){
        //Mur de droite
    }
    else{
        // Erreur
    }
}


// Getters
