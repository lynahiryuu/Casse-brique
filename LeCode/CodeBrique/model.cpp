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
    this->StartNewGame();
}


void Model::StartNewGame(){
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
    //Bas*//*
    Wall * wall_l = new Wall(4);
    walls_.push_back(wall_l);


    //Création de la balle
    ball_ = new Ball(-0.1,-0.1);
    ball2_ = new Ball(0.1,-0.1);
    ball3_ = new Ball(0.1,0.1);

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

    for(Brick* b: bricks_){
        b->Display();
    }
    for(Wall* w: walls_){
        w->Display();
    }
    ball_->Display();
    ball2_->Display();
    ball3_->Display();
    paddle_->Display();
}


int Model::get_H_Wid(){
    return height_W_;
}

int Model::get_W_Wid(){
    return width_W_;
}

void Model::update(const float timeInDays){

    this->LoseLife();
    this->WinGame();

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


    ball_->Move(timeInDays);
    ball2_->Move(timeInDays);
    ball3_->Move(timeInDays);

    paddle_->movePaddle(direction_paddle_);
    Display();

}

void Model::setDirectionPaddle(int direction){
    direction_paddle_= direction;
}
