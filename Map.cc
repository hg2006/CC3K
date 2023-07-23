#include "Map.h"
using namespace std;

Map::Map (BuffedPlayer* p): tiles { vector<unique_ptr<Cell>>{}}, player {p}
  { // create the initial map through hard coding
    this->genBoarderLine();
    this->genBlankLine();
    for (int i = 1; i > -1; --i){
      this->genChamber1(i);
      this->genGap1();
      this->genChamber2(i);
      this->genGap2();
    }
    this->genChamber1();
    tiles.emplace_back (make_unique <Door>());
    for (int i = 0; i < 8; ++i){
      tiles.emplace_back (make_unique <Passage>());
    }
    tiles.emplace_back (make_unique <Door>());
    this->genChamber2();
    tiles.emplace_back (make_unique <VerticalWall>());
    for (int i = 0; i < 7; ++i){
      tiles.emplace_back (make_unique <HorizontalWall>());
    }
    tiles.emplace_back (make_unique <VerticalWall>());
    for (int i = 0; i < 7; ++i){
      tiles.emplace_back (make_unique <Blank>());
    }
    tiles.emplace_back (make_unique <VerticalWall>());
    // Line 6 + 7
    for (int j = 0; j < 6; j += 3){
      this->genChamber1();
      this->genGap3();
      this->genChamber2();
      for (int i = 0; i < 8+j; ++i){
        tiles.emplace_back (make_unique <Room>());
      }
      tiles.emplace_back (make_unique <VerticalWall>());
      tiles.emplace_back (make_unique <HorizontalWall>());
      tiles.emplace_back (make_unique <HorizontalWall>());
      tiles.emplace_back (make_unique <VerticalWall>());
      for (int i = 0; i < 4-j; ++i){
        tiles.emplace_back (make_unique <Blank>());
      }
      tiles.emplace_back (make_unique <VerticalWall>());
    }
    // Line 8
    tiles.emplace_back (make_unique <VerticalWall>());
    this->genChmWall();
    for (int i = 0; i < 4; ++i){
      tiles.emplace_back (make_unique <HorizontalWall>());
    }
    this->genGap3();
    this->genChmWall2();
    tiles.emplace_back (make_unique <VerticalWall>());
    this->genChamber2Bottom();
    // Line 9
    this->genPassage1();
    for (int i = 0; i < 12; ++i){
      tiles.emplace_back (make_unique <Passage>());
    }
    for (int i = 0; i < 16; ++i){
      tiles.emplace_back (make_unique <Blank>());
    }
    tiles.emplace_back (make_unique <VerticalWall>());
    this->genChamber2Bottom();
    // Line 10
    this->genPassage1();
    this->genChmWall3();
    for (int i = 0; i < 6; ++i){
      tiles.emplace_back (make_unique <Blank>());
    }
    tiles.emplace_back (make_unique <VerticalWall>());
    this->genChamber2Bottom();
    // Line 11
    this->genPassage1();
    this->genChamber3();
    for (int i = 0; i < 6; ++i){
      tiles.emplace_back (make_unique <Blank>());
    }
    tiles.emplace_back (make_unique <VerticalWall>());
    this->genChamber2Bottom();
    // Line 12
    tiles.emplace_back (make_unique <VerticalWall>());
    for (int i = 0; i < 12; ++i){
      tiles.emplace_back (make_unique <Blank>());
    }
    for (int i = 0; i < 19; ++i){
      tiles.emplace_back (make_unique <Passage>());
    }
    this->genChamber3();
    for (int i = 0; i < 6; ++i){
      tiles.emplace_back (make_unique <Passage>());
    }
    tiles.emplace_back (make_unique <Door>());
    this->genChamber2Bottom();
    // Line 13
    this->genPassage1();
    this->genChamber3();
    tiles.emplace_back (make_unique <Passage>());
    for (int i = 0; i < 5; ++i){
      tiles.emplace_back (make_unique <Blank>());
    }
    tiles.emplace_back (make_unique <VerticalWall>());
    this->genChamber2Bottom();
    // Line 14
    this->genPassage1();
    this->genChmWall3();
    tiles.emplace_back (make_unique <Passage>());
    for (int i = 0; i < 5; ++i){
      tiles.emplace_back (make_unique <Blank>());
    }
    this->genChmWall4(4);
    // Line 15
    tiles.emplace_back (make_unique <VerticalWall>());
    tiles.emplace_back (make_unique <Blank>());
    this->genChmWall();
    this->genPassage2();
    for (int i = 0; i < 5; ++i){
      tiles.emplace_back (make_unique <Blank>());
    }
    tiles.emplace_back (make_unique <Passage>());
    for (int i = 0; i < 8; ++i){
      tiles.emplace_back (make_unique <Blank>());
    }
    tiles.emplace_back (make_unique <VerticalWall>());
    // Line 16
    this->genChamber4();
    this->genPassage2();
    this->genChmWall4();
    // Line 17
    this->genChamber4();
    this->genPassage2(1);
    this->genChamber5();
    // Line 18
    this->genChamber4();
    this->genPassage2();
    this->genChamber5();
    // Line 19
    this->genChamber4();
    this->genPassage3(1);
    tiles.emplace_back (make_unique <HorizontalWall>());
    tiles.emplace_back (make_unique <HorizontalWall>());
    this->genChmWall2();
    for (int i = 0; i < 4; ++i){
      tiles.emplace_back (make_unique <HorizontalWall>());
    }
    this->genChamber5();
    // Line 20
    this->genChamber4();
    this->genPassage3(1);
    this->genChamber5Bottom();
    // Line 21
    this->genChamber4();
    tiles.emplace_back (make_unique <Door>());
    for (int i = 0; i < 10; ++i ){
      tiles.emplace_back (make_unique <Passage>());
    }
    tiles.emplace_back (make_unique <Door>());
    this->genChamber5Bottom();
    // Line 22
    this->genChamber4();
    this->genPassage3();
    this->genChamber5Bottom();
    // Line 23
    this->genChamber4(1);
    this->genPassage3();
    this->genChamber5Bottom(1);
    
    this->genBlankLine();
    this->genBoarderLine();
  }

Map:: ~Map(){}

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

    for(auto &s:tiles){
        if(cur_col == howmanycol){
            cur_col = 0;
            cur_row++;
            cout << endl;
        }

        // If Player is located here
        //if(cur_col == Player_x && cur_row == Player_y )cout << '@';
        cout << s->Render();

        cur_col++;
    }
}

GameObject* Map:: GetObject(int row, int col) const{
    (tiles.at(row * howmanycol + col))->GetObject();
}

vector<CellType> Map:: Getviews(int row, int col) const{
    BuffedPlayer *player = this->player;
    int Player_x = player->Getx();
    int Player_y = player->Gety(); /*Getx and Gety funcion required*/
    int dist_x = Player_x - row;
    int dist_y = Player_y - col;

    vector<CellType> result(9, OBSTACLE);
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            int index = this->index_convert(row + i, col + j);

            if(index >= 0){
                // If player is located here, mark it PLAYER
                if(i == dist_x &&  j == dist_y){
                    result[3 * (i + 1) + (j + 1)] = PLAYER;
                }else{
                    CellType type = (tiles.at(index))->GetType();
                    result[3 * (i + 1) + (j + 1)] = type;
                }
            }
            // if out of range, then OBSTACLE automatically
            else{
                result[3 * (i + 1) + (j + 1)] = OBSTACLE;
            }
        }
    }

    return result;
}

    


void Map:: GenerateObject(int row, int col, MapItemType type){
        // switch (type){
        //     case HUMAN:
        //         GameObject *newobj = new Human{row, col};
        //         objects.emplace_back(newobj);
        //         this->Attach(row, col, newobj);
        //         break;
        //     case DWARF:
        //         GameObject *newobj = new Dwarf{row, col};
        //         objects.emplace_back(newobj);
        //         this->Attach(row, col, newobj);
        //         break;
        //     case ELF:
        //         GameObject *newobj = new Elf{row, col};
        //         objects.emplace_back(newobj);
        //         this->Attach(row, col, newobj);
        //         break;
        //     case ORCS:
        //         GameObject *newobj = new Orc{row, col};
        //         objects.emplace_back(newobj);
        //         this->Attach(row, col, newobj);
        //         break;
        //     case MERCHANT:
        //         GameObject *newobj = new Merchant{row, col};
        //         objects.emplace_back(newobj);
        //         this->Attach(row, col, newobj);
        //         break;
        //     case DRAGON:
        //         GameObject *newobj = new Dragon{row, col};
        //         objects.emplace_back(newobj);
        //         this->Attach(row, col, newobj);
        //         break;
        //     case HALFLING:
        //         GameObject *newobj = new Halfling{row, col};
        //         objects.emplace_back(newobj);
        //         this->Attach(row, col, newobj);
        //         break;
        //     case SMALLGOLD:
        //         GameObject *newobj = new Smallgold{row, col};
        //         objects.emplace_back(newobj);
        //         this->Attach(row, col, newobj);
        //         break;
        //     case NORMALGOLD:
        //         GameObject *newobj = new Normalgold{row, col};
        //         objects.emplace_back(newobj);
        //         this->Attach(row, col, newobj);
        //         break;
        //     case MERCHANTHOARD:
        //         GameObject *newobj = new MerchantHoard{row, col};
        //         objects.emplace_back(newobj);
        //         this->Attach(row, col, newobj);
        //         break;
        //     case DRAGONHOARD:
        //         GameObject *newobj = new DragonHoard{row, col};
        //         objects.emplace_back(newobj);
        //         this->Attach(row, col, newobj);
        //         break;
            
            // To be further implemented since ctor required    
            // case BA:
            // case BD:
            // case WA:
            // case WD:
            // case RH:
            // case PH:
        // }
}

void Map:: UpdateMap(){
    // Decision for player already done in interface?
    for(auto &s:tiles){
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

void Map::genBoarderLine() {
  tiles.emplace_back (make_unique <VerticalWall>());
  for (int i = 0; i < howmanycol-2; ++i){
    tiles.emplace_back (make_unique <HorizontalWall>());
  }
  tiles.emplace_back (make_unique <VerticalWall>());
}

void Map::genBlankLine() {
  tiles.emplace_back (make_unique <VerticalWall>());
  for (int i = 0; i < howmanycol-2; ++i){
    tiles.emplace_back (make_unique <Blank>());
  }
  tiles.emplace_back (make_unique <VerticalWall>());
}

void Map::genChamber1(int choice) {
  int colnum = 26;
  tiles.emplace_back (make_unique <VerticalWall>());
  tiles.emplace_back (make_unique <Blank>());
  tiles.emplace_back (make_unique <VerticalWall>());
  if (choice){
    for (int i = 0; i < colnum; ++i){
      tiles.emplace_back (make_unique <HorizontalWall>());
    }
  }
  else{
    for (int i = 0; i < colnum; ++i){
      tiles.emplace_back (make_unique <Room>());
    }
  }
}

void Map::genGap1() {
  int colnum = 8;
  tiles.emplace_back (make_unique <VerticalWall>());
  for (int i = 0; i < colnum; ++i){
    tiles.emplace_back (make_unique <Blank>());
  }
  tiles.emplace_back (make_unique <VerticalWall>());
}

void Map::genChamber2(int choice) {
  int colnum = 23;
  if (choice){
    for (int i = 0; i < colnum; ++i){
      tiles.emplace_back (make_unique <HorizontalWall>());
    }
  }
  else{
    for (int i = 0; i < colnum; ++i){
      tiles.emplace_back (make_unique <Room>());
    }
  }
}

void Map::genChamber2Bottom(){
  int colnum = 15;
  for (int i = 0; i < colnum; ++i){
    tiles.emplace_back (make_unique <Room>());
  }
  tiles.emplace_back (make_unique <VerticalWall>());
  tiles.emplace_back (make_unique <Blank>());
  tiles.emplace_back (make_unique <VerticalWall>());
}

void Map::genChamber3(){
  for (int i = 0; i < 5; ++i){
    tiles.emplace_back (make_unique <Blank>());
  }
  tiles.emplace_back (make_unique <VerticalWall>());
  for (int i = 0; i < 12; ++i){
    tiles.emplace_back (make_unique <Room>());
  }
  tiles.emplace_back (make_unique <VerticalWall>());
  for (int i = 0; i < 3; ++i){
    tiles.emplace_back (make_unique <Blank>());
  }
}

void Map::genGap2() {
  int colnum = 15;
  tiles.emplace_back (make_unique <VerticalWall>());
  for (int i = 0; i < colnum; ++i){
    tiles.emplace_back (make_unique <Blank>());
  }
  tiles.emplace_back (make_unique <VerticalWall>());
}

void Map::genGap3(){
  tiles.emplace_back (make_unique <VerticalWall>());
  for (int i = 0; i < 3; ++i){
    tiles.emplace_back (make_unique <Blank>());
  }
  tiles.emplace_back (make_unique <Passage>());
  for (int i = 0; i < 4; ++i){
    tiles.emplace_back (make_unique <Blank>());
  }
  tiles.emplace_back (make_unique <VerticalWall>());
}

void Map::genChmWall(){
  tiles.emplace_back (make_unique <Blank>());
  tiles.emplace_back (make_unique <VerticalWall>());
  for (int i = 0; i < 10; ++i){
    tiles.emplace_back (make_unique <HorizontalWall>());
  }
  tiles.emplace_back (make_unique <Door>());
  for (int i = 0; i < 11; ++i){
    tiles.emplace_back (make_unique <HorizontalWall>());
  }
}

void Map::genChmWall2(){
  for (int i = 0; i < 4; ++i){
    tiles.emplace_back (make_unique <HorizontalWall>());
  }
  tiles.emplace_back (make_unique <Door>());
  for (int i = 0; i < 16; ++i){
    tiles.emplace_back (make_unique <HorizontalWall>());
  }
}

void Map::genChmWall3(){
  for (int i = 0; i < 5; ++i){
    tiles.emplace_back (make_unique <Blank>());
  }
  tiles.emplace_back (make_unique <VerticalWall>());
  for (int i = 0; i < 5; ++i){
    tiles.emplace_back (make_unique <HorizontalWall>());
  }
  tiles.emplace_back (make_unique <Door>());
  for (int i = 0; i < 6; ++i){
    tiles.emplace_back (make_unique <HorizontalWall>());
  }
  tiles.emplace_back (make_unique <VerticalWall>());
  for (int i = 0; i < 3; ++i){
    tiles.emplace_back (make_unique <Blank>());
  }
}

void Map::genChmWall4(int extend){
  tiles.emplace_back (make_unique <VerticalWall>());
  for (int i = 0; i < 4+extend; ++i){
    tiles.emplace_back (make_unique <HorizontalWall>());
  }
  tiles.emplace_back (make_unique <Door>());
  for (int i = 0; i < 6; ++i){
    tiles.emplace_back (make_unique <HorizontalWall>());
  }
  tiles.emplace_back (make_unique <VerticalWall>());
  tiles.emplace_back (make_unique <Blank>());
  tiles.emplace_back (make_unique <VerticalWall>());
}

void Map::genPassage1(){
  tiles.emplace_back (make_unique <VerticalWall>());
  for (int i = 0; i < 12; ++i){
    tiles.emplace_back (make_unique <Blank>());
  }
  tiles.emplace_back (make_unique <Passage>());
  for (int i = 0; i < 17; ++i){
    tiles.emplace_back (make_unique <Blank>());
  }
  tiles.emplace_back (make_unique <Passage>());
}

void Map::genPassage2(int choice){
  tiles.emplace_back (make_unique <VerticalWall>());
  for (int i = 0; i < 5; ++i){
    tiles.emplace_back (make_unique <Blank>());
  }
  tiles.emplace_back (make_unique <Passage>());
  if (choice){
    for (int i = 0; i < 23; ++i){
      tiles.emplace_back (make_unique <Passage>());
    }
  }
  else{
    for (int i = 0; i < 11; ++i){
      tiles.emplace_back (make_unique <Blank>());
    }
    tiles.emplace_back (make_unique <Passage>());
    for (int i = 0; i < 10; ++i){
      tiles.emplace_back (make_unique <Blank>());
    }
    tiles.emplace_back (make_unique <Passage>());
  }
  for (int i = 0; i < 9; ++i){
    tiles.emplace_back (make_unique <Blank>());
  }
}

void Map::genChamber4(int choice){
  tiles.emplace_back (make_unique <VerticalWall>());
  tiles.emplace_back (make_unique <Blank>());
  tiles.emplace_back (make_unique <Blank>());
  tiles.emplace_back (make_unique <VerticalWall>());
  if (choice){
    for (int i = 0; i < 21; ++i){
      tiles.emplace_back (make_unique <HorizontalWall>());
    }
  }
  else{
    for (int i = 0; i < 21; ++i){
      tiles.emplace_back (make_unique <Room>());
    }
  } 
}

void Map::genChamber5(int choice){
  tiles.emplace_back (make_unique <VerticalWall>());
  if (choice){
    for (int i = 0; i < 11; ++i){
      tiles.emplace_back (make_unique <HorizontalWall>());
    }
  }
  else{
    for (int i = 0; i < 11; ++i){
      tiles.emplace_back (make_unique <Room>());
    }
  }
  tiles.emplace_back (make_unique <VerticalWall>());
  tiles.emplace_back (make_unique <Blank>());
  tiles.emplace_back (make_unique <VerticalWall>());
}

void Map::genPassage3 (int choice){
  tiles.emplace_back (make_unique <VerticalWall>());
  for (int i = 0; i < 5; ++i){
    tiles.emplace_back (make_unique <Blank>());
  }
  if (choice){
    tiles.emplace_back (make_unique <Passage>());
  }
  else{
    tiles.emplace_back (make_unique <Blank>());
  }
  for (int i = 0; i < 4; ++i){
    tiles.emplace_back (make_unique <Blank>());
  }
  tiles.emplace_back (make_unique <VerticalWall>());
}

void Map::genChamber5Bottom(int choice) {
  if (choice){
    for (int i = 0; i < 39; ++i){
      tiles.emplace_back (make_unique <HorizontalWall>());
    }
  }
  else{
    for (int i = 0; i < 39; ++i){
      tiles.emplace_back (make_unique <Room>());
    }
  }
  tiles.emplace_back (make_unique <VerticalWall>());
  tiles.emplace_back (make_unique <Blank>());
  tiles.emplace_back (make_unique <VerticalWall>());
}

void Map:: InitializeMap(){
    // initialize shuffled chambers using hard coding
    vector <int> chamber1;
    for (int i = 240; i < 266; ++i){
        for (int j = 0; j < 4; ++j){
            chamber1.emplace_back(i+j*howmanycol);
        }
    }
    vector <int> chamber2;
    for (int i = 276; i < 299; ++i){
        for (int j = 0; j < 4; ++j){
            chamber2.emplace_back(i+j*howmanycol);
        }
    }
    for (int i = 457; i < 465; ++i){
        chamber2.emplace_back(i);
        chamber2.emplace_back(i+howmanycol);
    }
    chamber2.emplace_back(544);
    chamber2.emplace_back(545);
    chamber2.emplace_back(546);
    for (int i = 614; i < 629; ++i){
        for (int j = 0; j < 6; ++j){
            chamber2.emplace_back(i+j*howmanycol);
        }
    }
    vector <int> chamber3;
    for (int i = 828; i < 840; ++i){
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
    for (int i = 1538; i < 1577; ++i){
        for (int j = 0; j < 3; ++j){
            chamber5.emplace_back(i+j*howmanycol);
        }
    }
    for (int i = 1487; i < 1498; ++i){
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
        switch (rand()%6){
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
            InsertBoth(chamber, coord/howmanycol, coord%howmanycol);
            chamber.erase(find(chamber.begin(), chamber.end(), coord));
            x = 1;
            break;
        }
        catch (...){ 
            // invalid coordination, does nothing, goes to next iteration
        }
    }
    if (!x) { throw x; } // chamber is invalid
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

