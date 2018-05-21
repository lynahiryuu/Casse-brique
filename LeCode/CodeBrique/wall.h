#ifndef WALL_H
#define WALL_H
#include "reflector.h"
#include <GL/glu.h>


/* Classe héritée de la classe abstraite Reflector()
 * permettant de construire un mur, de l'afficher et d'interagir avec les autres composants du jeu
 */

class Wall : public Reflector{
public:

    //Constructeur
    Wall(int id);

    //Destructeur
    ~Wall();

    /* Méthode issue de la classe abstraite Reflector
     * permettant de faire rebondir la balle lorsque celle-ci touche un mur et de détruire la balle si elle touche le mur du bas
     */
    void Bounce(Ball *b) ;

    /* Méthode issue de la classe abstraite Reflector
     * permettant d'afficher le mur
     */
    void Display() const;

    //Getters
    int getId();
    void setId(int id);
    bool getDestructor();

    //Setters
    void setDestructor(bool destructor);

private:

    //Numéro du mur, afin de déterminer si c'est le mur du bas (= 4), du haut (= 2), de gauche (= 1) ou de droite (= 3)
    int id_;

    //Longueur du mur (= 30 si c'est le mur du haut et bas et = 12 sinon)
    double weight_;

    //Coordonnées en bas à droite du mur qui est un parallélépipède
    double x_;
    double y_;

    //Renvoie true si la balle a touchée le mur du bas et false sinon
    bool destructor_;
};

#endif // WALL_H
