#include "model.h"
#include <random>
#include <vector>
#include <algorithm>
#include "brick.h"
#include "wall.h"
#include "player.h"
#include "paddle.h"
#include "mainwindow.h"



Model::Model()
{
    ball_=new Ball();
    paddle_=new Paddle(0,15);

    this->StartNewGame();
}


void Model::StartNewGame(){
    int NbBricks=rand()%50+50;
    //bricks->push_back(Brick(1,2));
    vector<int> *ListPos;

    //Génération aléatoire de briques
    int tempo=-1;
    for(int j=0;j<NbBricks;j++){
        while(std::find(ListPos->begin(), ListPos->end(), tempo) != ListPos->end()){
            tempo=rand()%100;
        }
        ListPos->push_back(tempo);
    }


    for(int i=0;i<NbBricks;i++){
        int pos = ListPos->at(i);
        Brick* brique = new Brick(pos,pos);
        bricks_.push_back(brique);
    }

    //Création des murs

    //Gauhe
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
    ball_ = new Ball();

    //Création du paddle
    paddle_ = new Paddle(width_W_/2, height_W_/12);

    //Création du joueur
    player_ = new Player("Player1");

}






void Model::LoseLife()
{
    player_->setHP( player_->getHP()-1 );
}
bool Model::LoseGame()
{
    if (player_->getHP() == 0)
    {
        return true;
    }
    return false;
}

bool Model::WinGame()
{
    bool win = LoseGame();
    if (win == false && bricks_.empty()){
        return true;
    }
    return false;
}


void Model::Display() const{
    for(Brick* b: bricks_){
        b->Display();
    }
    for(Wall* w: walls_){
        w->Display();
    }
    ball_->Display();
    paddle_->Display();
}




int Model::get_H_Wid(){
    return height_W_;
}

int Model::get_W_Wid(){
    return width_W_;
}
