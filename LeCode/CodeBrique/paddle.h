#ifndef PADDLE_H
#define PADDLE_H
#include "reflector.h"
#include <GL/glu.h>

/*
* Classe héritée de la classe abstraite Reflector()
* permettant de construire un palet, de l'afficher et d'interagir avec les autres composants du jeu
*/

class Paddle : public Reflector{
public:

    //Constructeur
    Paddle(double x, double y);

    //Destructeur
    ~Paddle();

    /* Méthode issue de la classe abstraite Reflector
     * permettant de faire rebondir la balle lorsque celle-ci touche le paddle
     */
    void Bounce(Ball *b);

    //Setters
    void setX(double x);

    /* Méthode issue de la classe abstraite Reflector
     * permettant d'afficher le paddle
     */
    void Display() const;

    //Getters
    double getX();

    //Méthode permettant de faire bouger le paddle selon une direction donnée en paramètres (0 : immobile, 1: gauche ou -1: droite)
    void movePaddle(int direction);


private:
    // Enregistre la coordonnée du point en bas à droite du paddle
    double x_;
    double y_;

    //Hauteur et longueur du paddle
    double heigth_;
    double width_;

    //Attribut contenant la direction du paddle (0 : immobile, 1: gauche ou -1: droite)
    int direction_;

};

#endif // PADDLE_H
