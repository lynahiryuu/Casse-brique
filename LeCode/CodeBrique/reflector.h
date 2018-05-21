#ifndef REFLECTOR_H
#define REFLECTOR_H
#include "ball.h"

/*
 * Classe abstraite dont seront issues les classes Wall, Brick et Paddle.
 * Cette classe offre deux méthodes :  Une pour l'affichage des composants qui hériteront de la méthode
 * et une autre permettant de gérer le rebond de la balle. Les trois classes héritantes font en effet rebondir la balle
 * lorsqu'elle entre en contact avec ces derniers d'où le nom de Reflector.
*/


class Reflector
{

public:
    //Constrcteur
    Reflector();

    //Méthode virtuelle qui gérera l'affichage dans les classes héritantes
    virtual void Display()const =0;

    //Méthode vituelle qui gérera le rebond dans les classes héritantes
    virtual void Bounce(Ball* b)=0;


};

#endif // REFLECTOR_H
