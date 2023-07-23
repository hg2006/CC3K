#include "Map.h"
using namespace std;

Map:: Map(): tiles{nullptr} {}

Map:: ~Map(){}

void Map:: InitializeMap(){
    /* To do*/
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

