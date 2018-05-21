#ifndef MODEL_H
#define MODEL_H
#include "brick.h"
#include "paddle.h"
#include "wall.h"
#include "ball.h"
#include "player.h"
#include "mainwindow.h"

#include <vector>

/*
 * Classe qui permet de gérer toutes les interactions entre les objets du jeu. Elle gère aussi le déroulement de la partie,
 * la mise à jour des différents composants ainsi que l'affichage.
*/


class Model
{
public:

    //Constructeur
    Model();

    //Méthode permettant de commencer une partie. Elle est appelée dans le constructeur et après la perte d'une partie. Elle initialise tous les composants.
    void StartNewGame();

    //Méthode gérant les points de vie du joueur. Le joueur perd une vie à chaque balle touchant le mur du bas
    void LoseLife();

    /*Méthode gérant la perte d'une partie. Le joueur perd une partie quand tous ses points de vies sont épuisés.
     *  Renvoie true si le joueur a perdu et false sinon
     */
    bool LoseGame();

    //Méthode gérant la victoire du joeur. Celui-ci gagne si toutes les briques sont cassées et qu'il a encore des points de vie.
    void WinGame();

    //Getters
    int get_H_Wid();
    int get_W_Wid();
    bool get_start_ball_();

    //Méthode permettant d'afficher les composants du jeu
    void Display() const;

    //Méthode permettant de mettre à jour les composants
    void update();

    //Setters
    void setDirectionPaddle(int direction);
    void set_start_ball_(bool start);


private:

    //Vecteur contenant toutes les briques du jeu
    vector<Brick *> bricks_;

    //Vecteur contenant tous les murs du jeu
    vector<Wall *> walls_;

    //Pointeurs pointant sur 3 objets Ball : Permet de créer 3 balles
    Ball *ball_;
    Ball *ball2_;
    Ball *ball3_;

    //Création du Palet
    Paddle *paddle_;

    //Création du joueur
    Player *player_;

    //Pointeur pointant vers la fenêtre principale
    MainWindow *main_;

    //Attribut permettant de savoir la taille de la fenêtre
    int width_W_;
    int height_W_;

    //Attribut stockant l'entier permettant se savoir si le palet doit se déplacer à gauche (=1), à droite (=-1) ou doit rester immobile (=0)
    int direction_paddle_;

    //Stockage de la taille du vecteur contenant les briques afin de le comparer au nombre de briques brisées
    int size_brick_;

    //Booléen à true pour pouvoir déplacer les balle, false sinon
    bool start_ball_;
};

#endif // MODEL_H
