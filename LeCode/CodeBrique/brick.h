#ifndef BRICK_H
#define BRICK_H
#include "reflector.h"
#include <GL/glu.h>
#include <QString>
#include <QImage>
#include <QGLWidget>

/*
 * Classe héritée de la classe abstraite Reflector()
 * permettant de construire une brique, de l'afficher ou non et d'interagir avec les autres composants du jeu
 */


class Brick : public Reflector
{

public:

    //Constructeur
    Brick(float x, float y);

    //Destructeur
    ~Brick();

    /* Méthode issue de la classe abstraite Reflector
     * permettant de faire rebondir la balle lorsque celle-ci touche la brique et de détruire la brique touchée
     */
    void Bounce(Ball *b);

    //Getters
    int getX();
    int getY();
    int get_nb_broken_brick();
    bool getHit();

    //Setters
    void setX(int x);
    void setY(int y);
    void setHit(bool b);

    /* Méthode issue de la classe abstraite Reflector
     * permettant d'afficher la brique
     */
    void Display() const;


private:

    //Attribut permettant de savoir combien de briques ont été touchées
    int nb_broken_brick_;

    // Attribut qui permet de savoir si la brique a été touchée à cet instant
    bool hit_;

    //Coordonnées en bas à droite de la brique
    GLfloat x_;
    GLfloat y_;

    //Hauteur et longueur de la brique
    double heigth_;
    double width_;

    //Permet de stocker le chemin pour la texture des briques
    QString imPath_;

    //Renvoie true si la brique a été touchée par la balle et false sinon
    bool destroy_;

};

#endif // BRICK_H
