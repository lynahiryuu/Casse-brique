#ifndef BALL_H
#define BALL_H
#include <typeinfo>
#include <GL/glu.h>

/*
* Classe permettant de construire une balle, de la faire bouger, de l'afficher et d'interagir avec les autres composants du jeu
*/

class Ball
{
public:
    //Constructeur
    Ball(double speedx, double speedy);
    //Destructeur
    ~Ball();
    //Méthode permettant à la balle de bouger
    void Move();
    //Méthode permettant de savoir si la balle touche un mur, une brique ou un paddle. Retourne true si c'est le cas.
    boolean Into(double x1, double y1, double x2, double y2);

    //getters
    double getx_();
    double gety_();
    double getspeedx_() const;
    double getspeedy_() const;
    double getRadius_() const;
    bool get_start_();
    bool get_destructed_();

    //setters
    void setx_(double x);
    void sety_(double y);
    void setspeedx_(double speedx);
    void setspeedy_(double speedy);
    void set_start_(bool start);
    void set_destructed_(bool destructed);

    //Méthode permettant d'afficher la balle
    void Display() const;

private:

    //Rayon
    double radius_;
    //Coordonnées du centre de la balle
    double x_;
    double y_;
    //Vitesse de la balle en x et y
    double speedx_;
    double speedy_;
    //Création du modèle graphique de la balle
    GLUquadric *ball_quadric_;
    //Attribut à false si la balle ne touche pas le mur du bas et à true sinon
    bool destructed_;
    //Attribut à false en début de partie pour éviter que la balle ne parte sans l'accord du joueur, il doit être à true pour déplacer la balle
    bool start_;


};

#endif // BALL_H
