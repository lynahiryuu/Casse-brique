#include "model.h"
#include <random>
#include <vector>
#include <algorithm>
#include "brick.h"
#include "wall.h"
#include "player.h"
#include "paddle.h"
#include "mainwindow.h"

Model::Model(MainWindow *m)
{
   main_ = m;
   width_W_ = main_->getWidth();
   height_W_ = main_->getHeight();
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

    //Haut
    Wall * wall_h = new Wall(1,1,width_W_,1);
    walls_.push_back(wall_h);

    //Bas
    Wall * wall_d = new Wall(1,height_W_,width_W_,height_W_);
    walls_.push_back(wall_d);
    //Droite
    Wall * wall_r = new Wall(height_W_,width_W_,height_W_,width_W_);
    walls_.push_back(wall_r);
    //Gauche
    Wall * wall_l = new Wall(1,1,1,height_W_);
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

int Model::get_H_Wid(){
    return height_W_;
}

int Model::get_W_Wid(){
    return width_W_;
}
