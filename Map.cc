#include "Map.h"
using namespace std;

Map:: ~Map(){}

void Map:: InitializeMap(){
    // initialize shuffled chambers using hard coding
    vector <int> chamber1;
    for (int i = 240; i < 267; ++i){
        for (int j = 0; j < 4; ++j){
            chamber1.emplace_back(i+j*howmanycol);
        }
    }
    vector <int> chamber2;
    for (int i = 277; i < 300; ++i){
        for (int j = 0; j < 4; ++j){
            chamber2.emplace_back(i+j*howmanycol);
        }
    }
    for (int i = 458; i < 466; ++i){
        chamber2.emplace_back(i);
        chamber2.emplace_back(i+howmanycol);
    }
    chamber2.emplace_back(545);
    chamber2.emplace_back(546);
    chamber2.emplace_back(547);
    for (int i = 615; i < 630; ++i){
        for (int j = 0; j < 6; ++j){
            chamber2.emplace_back(i+j*howmanycol);
        }
    }
    vector <int> chamber3;
    for (int i = 829; i < 841; ++i){
        for (int j = 0; j < 3; ++j){
            chamber3.emplace_back(i+j*howmanycol);
        }
    }
    vector <int> chamber4;
    for (int i = 1189; i < 1210; ++i){
        for (int j = 0; j < 7; ++j){
            chamber4.emplace_back(i+j*howmanycol);
        }
    }
    vector <int> chamber5;
    for (int i = 1539; i < 1578; ++i){
        for (int j = 0; j < 3; ++j){
            chamber5.emplace_back(i+j*howmanycol);
        }
    }
    for (int i = 1488; i < 1499; ++i){
        for (int j = 0; j < 3; ++j){
            chamber5.emplace_back(i-j*howmanycol);
        }
    }
    random_device rd;
    shuffle(chamber1.begin(), chamber1.end(), rd);
    shuffle(chamber2.begin(), chamber2.end(), rd);
    shuffle(chamber3.begin(), chamber3.end(), rd);
    shuffle(chamber4.begin(), chamber4.end(), rd);
    shuffle(chamber5.begin(), chamber5.end(), rd);
    vector < vector <int> > chambers {chamber1, chamber2, chamber3, chamber4, chamber5};


    vector <int> chambernum {0, 1, 2, 3, 4};
    shuffle(chambernum.begin(), chambernum.end(), rd);
    int playerchamber = chambernum.back();
    chambernum.pop_back();
    int stairchamber = chambernum.back();
    // potion + gold + enemy


}

void Map::InsertChamber(vector < vector <int> > &chambers, int index, MapItemType type){
    vector <int> & chamber = chambers.at(index);
    if (chamber.empty()) { throw index; } // no more space in this chamber
    
}


// @ for player
// E for all enemies
// P for all potions
// G for gold

void Map:: RenderMap() const{
    int cur_col = 0;
    int cur_row = 0;
    
    BuffedPlayer *player = this->player;
    int Player_x = player->Getx();
    int Player_y = player->Gety(); /*Getx and Gety funcion required*/

    for(auto s:tiles){
        if(cur_col == howmanycol){
            cur_col = 0;
            cur_row++;
            cout << endl;
        }

        // If Player is located here
        if(cur_col == Player_x && cur_row == Player_y )cout << 'P';
        else cout << s->Render();

        cur_col++;
    }
}

GameObject* Map:: GetObject(int row, int col) const{
    (tiles.at(row * howmanycol + col))->GetObject();
}

CellType * Map:: Getviews(int row, int col) const{
    /*To do*/
}

void Map:: UpdateMap(){
    // Decision for player already done in interface?
    for(auto s:tiles){
        GameObject* obj = s->GetObject();
        if(obj){
            obj->update();
            // Update function required
        }
    }

}

void Map:: Attach(int row, int col, GameObject *obj){
    // To avoid transferring of unique ptr
    (tiles.at(row*howmanycol + col))->Attach(obj);
}

void Map:: Detach(int row, int col){
    (tiles.at(row*howmanycol + col))->Detach();
}

