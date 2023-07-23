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

    // generate player coordinate
    // ***TODO: Door?
    vector <int> chambernum {0, 1, 2, 3, 4};
    shuffle(chambernum.begin(), chambernum.end(), rd);
    int playerindex = chambernum.back();
    vector <int> & playerchamber = chambers.at(playerindex);
    int coord = playerchamber.back();
    this->player->row = coord/howmanycol;
    this->player->col = coord%howmanycol;
    playerchamber.pop_back();
    
    // generate stair
    chambernum.pop_back();
    int stairchamber = chambernum.back();
    this->InsertChamber(chambers, stairchamber, ASTAIR);

    srand (time(NULL));

    // generate potions
    for (int i = 0; i < 10; ++i){
        int potionchamber = rand()%5;
        MapItemType ptype;
        swich (rand()%6){
            case 0: ptype = BA;
            case 1: ptype = BD;
            case 2: ptype = WA;
            case 3: ptype = WD;
            case 4: ptype = RH;
            case 5: ptype = PH;
        }
        this->InsertChamber(chambers, potionchamber, ptype);
    }

    // generate golds
    for (int i = 0; i < 10; ++i){
        int goldchamber = rand()%5;
        int type = rand()%8;
        if (!type){ // dragon hoard
            try {
                this->InsertDragonHoard(chambers, goldchamber);
            }
            catch (int x){
                int newindex = (x + rand()%4 + 1) % 5;
                this->InsertDragonHoard(chambers, newindex);
            }
        }
        else if (type == 1 || type == 2){
            this->InsertChamber(chambers, goldchamber, SMALLGOLD);
        }
        else{
            this->InsertChamber(chambers, goldchamber, NORMALGOLD);
        }
    }

    // generate enemies
    for (int i = 0; i < 20; ++i){
        int enemychamber = rand()%5;
        int type = rand()%18;
        MapItemType etype;
        if (type >= 0 && type <= 3){
            etype = HUMAN;
        }
        else if (type >= 4 && type <= 6){
            etype = DWARF;
        }
        else if (type >= 7 && type <= 11){
            etype = HALFLING;
        }
        else if (type >= 12 && type <= 13){
            etype = ELF;
        }
        else if (type >= 14 && type <= 15){
            etype = ORCS;
        }
        else{
            etype = MERCHANT;
        }
        try {
            this->InsertChamber(chambers, enemychamber, etype);
        }
        catch (int x){
            int newindex = (x + rand()%4 + 1) % 5;
            this->InsertChamber(chambers, newindex, etype);
        }
    }
}

void Map::InsertChamber(vector < vector <int> > &chambers, int index, MapItemType type){
    vector <int> & chamber = chambers.at(index);
    if (chamber.empty()) { throw index; } 
    // no more space in this chamber, only considered at enemy generation
    int coord = chamber.back();
    this->GenerateObject(coord/howmanycol, coord%howmanycol, type);
    chamber.pop_back();
}

void Map::InsertDragonHoard(vector < vector <int> > &chambers, int index){
    vector <int> & chamber = chambers.at(index);
    int x = 0;
    for (auto coord:chamber){
        try{
            InsertBoth(chamber, coord/howmanycol, corrd%howmanycol);
            chamber.erase(find(chamber.begin(), chamber.end(), coord));
            x = 1;
            break;
        }
        catch (...){ 
            // invalid coordination, does nothing, goes to next iteration
        }
    }
    if (!x) { throw x }; // chamber is invalid
}

void Map::InsertBoth(vector <int> &chamber, int row, int col){
    vector <CellType> adjacent = Getviews (row, col);
    vector <int> available;
    int ctr = 0;
    for (auto type : adjacent){
        if (ctr != 4 && type == ROOM){
            available.emplace_back((row+ctr/3)*79+col+ctr%3);
        }
        ctr += 1;
    }
    if (available.empty()) { throw 1; }
    random_device rd;
    shuffle(available.begin(), available.end(), rd);
    int coord = available.back();
    this->GenerateObject(row, col, DRAGONHOARD);
    this->GenerateObject(coord/howmanycol, coord%howmanycol, DRAGON);
    chamber.erase(find(chamber.begin(), chamber.end(), coord));
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

