#include "model.h"
#include <random>
#include <vector>
#include <algorithm>
#include "brick.h"
#include "wall.h"

Model::Model()
{

}


void Model::StartNewGame(){
    int NbBricks=rand()%50+50;
    bricks->push_back(Brick(1,2));
    vector<int> *ListPos;
    int tempo=-1;
    for(int j=0;j<NbBricks;j++){
        while(std::find(ListPos->begin(), ListPos->end(), tempo) != ListPos->end()){
            tempo=rand()%100;
        }
        ListPos->push_back(tempo);
    }

    for(int i=0;i<NbBricks;i++){
        int pos=ListPos->at(i);

        Reflector *r;
        Wall w(true);
        r = &w;
        //Brick *b=new Brick(1,2);
        //bricks->push_back(b);
        // ATTENTION CA MARCHE PAS!
        //bricks->push_back();
    }
}
