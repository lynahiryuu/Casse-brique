#include "model.h"

#include "brick.h"
#include "wall.h"
#include "player.h"
#include "paddle.h"
#include "mainwindow.h"

#include <algorithm>
#include <random>
#include <vector>
#include <iostream>
using namespace std;



Model::Model()
{
    direction_paddle_ = 0;
    start_ball_ = true;
    this->StartNewGame();
}


void Model::StartNewGame(){

    //cout<<"on est dans le start"<<endl;

    //Création des briques
    for(int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            GLfloat a = GLfloat(i);
            GLfloat b = GLfloat(j);
                    bricks_.push_back(new Brick(12-3.1*a,(-9.0f+b*1.1)));
        }
    }

    //Récupération de la taille des briques
    size_brick_=bricks_.size();

    //Création des murs

    //Gauche
    Wall * wall_h = new Wall(1);
    walls_.push_back(wall_h);

    //Haut
   Wall * wall_d = new Wall(2);
    walls_.push_back(wall_d);

    //Droite
    Wall * wall_r = new Wall(3);
    walls_.push_back(wall_r);

    //Bas
    Wall * wall_l = new Wall(4);
    walls_.push_back(wall_l);


    //Création de la balle
    ball_ = new Ball(0.1,0.1);
    ball2_ = new Ball(0.1,-0.1);
    ball3_ = new Ball(-0.1,0.1);

    //Création du paddle
    paddle_ = new Paddle(0,5);

    //Création du joueur
    player_ = new Player("Player1");

}



void Model::LoseLife()
{
    //Si on a touché le mur du bas, alors on perds un point de vie
    if (walls_[0]->getDestructor())
    {

        //cout<<player_->getHP()<<endl;
        player_->setHP(player_->getHP()-1);
        cout<<"Tu perds un point de vie"<<endl;

        //On réinitialise la condition
        walls_[0]->setDestructor(false);
    }
}
bool Model::LoseGame()
{
    //Si le joueur n'a plus de points de vie alors il perd la partie
    if (player_->getHP() == 0)
    {
        cout<<"You lose !"<<endl;

        //On relance alors le jeu
        StartNewGame();

        return true;
    }
    return false;
}

void Model::WinGame()
{
    //Si le joueur a encore des points de vie et si le nombre de briques cassées équivaut à la taille des briques, alors le joueur gagne la partie
    bool lost = LoseGame();

    if (lost == false && size_brick_ == bricks_[0]->get_nb_broken_brick()){
        cout<<"You win !"<<endl;
    }
}


void Model::Display() const{

    // Affichage de toutes les briques
    for(Brick* b: bricks_){
        b->Display();
    }

    // Affichage de tous les murs
    for(Wall* w: walls_){
        w->Display();
    }

    // Affichage des balles
    ball_->Display();
    ball2_->Display();
    ball3_->Display();

    // Affichage du paddle
    paddle_->Display();
}

//Getters

int Model::get_H_Wid(){
    return height_W_;
}

int Model::get_W_Wid(){
    return width_W_;
}

void Model::update(){

    //Si on autorise le mouvement de la balle en début de partie, alors les balles pourront se déplacer
    if (start_ball_){

        ball_->set_start_(true);
        ball2_->set_start_(true);
        ball3_->set_start_(true);
    }

    this->LoseLife();
    this->WinGame();

    // Teste si la balle rebondit sur un mur, une brique ou un paddle
    for(Brick* b: bricks_){
        b->Bounce(ball_);
        b->Bounce(ball2_);
        b->Bounce(ball3_);
    }

    walls_[0]->Bounce(ball_);
    walls_[0]->Bounce(ball2_);
    walls_[0]->Bounce(ball3_);

    paddle_->Bounce(ball_);
    paddle_->Bounce(ball2_);
    paddle_->Bounce(ball3_);

    // Déplacement de la balle
    ball_->Move();
    ball2_->Move();
    ball3_->Move();

    // Déplacement du palet
    paddle_->movePaddle(direction_paddle_);

    // Appel de la fonction d'affichage
    Display();

}


//Setters

void Model::setDirectionPaddle(int direction){
    direction_paddle_= direction;
}

void Model::set_start_ball_(bool start){
    start_ball_ = start;
}

bool Model::get_start_ball_(){
    return start_ball_;
}
