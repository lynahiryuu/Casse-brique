#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

/*
 * Classe permettant de créer un joueur, de gérer ses points de vies, son nom et ses scores
 */

class Player
{
public:

    //Constructeur
    Player(string name);

    //Getters
    int getHP();
    int getScore();

    //Setters
    void setHP(int HP);
    void setScore(int score);

private:

    //Attribut contenant le score
    int score_;

    //Attribut contenant le nom du joueur
    string name_;

    //Attribut contenant ses points de vie
    int HP_;

};

#endif // PLAYER_H
