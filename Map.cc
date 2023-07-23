#include "Map.h"
using namespace std;

Map:: Map(): tiles{nullptr} {}

Map:: ~Map(){}

void Map:: InitializeMap(){
    /* To do*/
}


// @ for player
// H for Human
// D for Dwarf
// E for Elf
// O for Orcs
// M for Merchant
// d for Dragon
// h for Halfing
// P for all potions
// G for gold
// R for Dragonhoard

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
        if(cur_col == Player_x && cur_row == Player_y )cout << '@';
        else cout << s->Render();

        cur_col++;
    }
}

GameObject* Map:: GetObject(int row, int col) const{
    (tiles.at(row * howmanycol + col))->GetObject();
}

CellType * Map:: Getviews(int row, int col) const{
    BuffedPlayer *player = this->player;
    int Player_x = player->Getx();
    int Player_y = player->Gety(); /*Getx and Gety funcion required*/
    int dist_x = row - Player_x;
    int dist_y = col - Player_y;

    bool in_range_x = -1 <= dist_x && dist_x <= 1;
    bool in_range_y = -1 <= dist_y && dist_y <= 1;
    bool player_view = (dist_x == 0) && (dist_y == 0);

    CellType result[8];

    // If player is not located on the spot, but located on a
    // spot within the box surrounding the spot, then the
    // first element of returning array will be PLAYER,
    // other elements irrelevant
    if(in_range_x && in_range_y && !player_view){
        result[0] = PLAYER; 
    }else{
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(i == 0 && j == 0) continue;

                int index = this->index_convert(row + i, col + j);
                if(index >= 0){
                    CellType type = (tiles.at(index))->GetType();
                    result[3 * (i + 1) + (j + 1)] = type;
                }
                // if out of range, then OBSTACLE automatically
                else{result[3 * (i + 1) + (j + 1)] = OBSTACLE;}

            }
        }
    }

    return result;
}

void Map:: GenerateObject(int row, int col, MapItemType type){
        switch (type){
            case HUMAN:
                GameObject *newobj = new Human{row, col};
                objects.emplace_back(newobj);
                this->Attach(row, col, newobj);
                break;
            case DWARF:
                GameObject *newobj = new Dwarf{row, col};
                objects.emplace_back(newobj);
                this->Attach(row, col, newobj);
                break;
            case ELF:
                GameObject *newobj = new Elf{row, col};
                objects.emplace_back(newobj);
                this->Attach(row, col, newobj);
                break;
            case ORCS:
                GameObject *newobj = new Orc{row, col};
                objects.emplace_back(newobj);
                this->Attach(row, col, newobj);
                break;
            case MERCHANT:
                GameObject *newobj = new Merchant{row, col};
                objects.emplace_back(newobj);
                this->Attach(row, col, newobj);
                break;
            case DRAGON:
                GameObject *newobj = new Dragon{row, col};
                objects.emplace_back(newobj);
                this->Attach(row, col, newobj);
                break;
            case HALFLING:
                GameObject *newobj = new Halfling{row, col};
                objects.emplace_back(newobj);
                this->Attach(row, col, newobj);
                break;
            case SMALLGOLD:
                GameObject *newobj = new Smallgold{row, col};
                objects.emplace_back(newobj);
                this->Attach(row, col, newobj);
                break;
            case NORMALGOLD:
                GameObject *newobj = new Normalgold{row, col};
                objects.emplace_back(newobj);
                this->Attach(row, col, newobj);
                break;
            case MERCHANTHOARD:
                GameObject *newobj = new MerchantHoard{row, col};
                objects.emplace_back(newobj);
                this->Attach(row, col, newobj);
                break;
            case DRAGONHOARD:
                GameObject *newobj = new DragonHoard{row, col};
                objects.emplace_back(newobj);
                this->Attach(row, col, newobj);
                break;
            
            // To be further implemented since ctor required    
            // case BA:
            // case BD:
            // case WA:
            // case WD:
            // case RH:
            // case PH:
        }
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

int Map:: index_convert(int row, int col) const{
    // if invalid row/col number, return -1
    if(row >= howmanyrow || col >= howmanycol) return -1;

    return row * howmanycol + col;
}
