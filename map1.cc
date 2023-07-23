#include "Map.h"
using namespace std;

Map::Map (BuffedPlayer* p): tiles { vector < < unique_ptr <Cell> > temp }, player {p}
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
      tiles.emplace_back (make_unique <Blank>());
    }
    for (int i = 0; i < 16; ++i){
      tiles.emplace_back (make_unique <HorizontalWall>());
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
    tiles.emplace_back (make_unique <VerticalWall>());
    this->genChmWall4(4);
    // Line 15
    tiles.emplace_back (make_unique <VerticalWall>());
    tiles.emplace_back (make_unique <Blank>());
    this->genChmWall();
    this->genPassage2();
    tiles.emplace_back (make_unique <VerticalWall>());
    for (int i = 0; i < 5; ++i){
      tiles.emplace_back (make_unique <Blank>());
    }
    tiles.emplace_back (make_unique <Door>());
    for (int i = 0; i < 8; ++i){
      tiles.emplace_back (make_unique <Blank>());
    }
    tiles.emplace_back (make_unique <VerticalWall>());
    // Line 16
    this->genChamber4();
    this->genPassage2();
    tiles.emplace_back (make_unique <VerticalWall>());
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





// helper functions to generate the initial map


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

void Map::genChamber4(){
  tiles.emplace_back (make_unique <VerticalWall>());
  tiles.emplace_back (make_unique <Blank>());
  tiles.emplace_back (make_unique <Blank>());
  tiles.emplace_back (make_unique <VerticalWall>());
  for (int i = 0; i < 21; ++i){
    tiles.emplace_back (make_unique <Room>());
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

