#ifndef _MAP_H_
#define _MAP_H_

#include "cc3klib.h"

#include "Cell.h"
#include "Room.h"
#include "Passage.h"
#include "Door.h"
#include "Blank.h"
#include "VerticalWall.h"
#include "HorizontalWall.h"
#include "Stair.h"

class BuffedPlayer;


class Map{
    std::vector < std::unique_ptr<Cell>> tiles;   // A vector of 1975 elements
    std::vector <std::unique_ptr<GameObject>> objects;
    BuffedPlayer *player;
    const int howmanyrow = 25;
    const int howmanycol = 79;
    
    Map(BuffedPlayer* p);
    ~Map();
    void InitializeMap();
    void RenderMap() const;
    void UpdateMap();

    void genBoarderLine();
    void genBlankLine();
    void genChamber1(int choice = 0);
    void genGap1();
    void genChamber2(int choice = 0);
    void genChamber2Bottom();
    void genChamber3();
    void genGap2();
    void genGap3();
    void genChmWall();
    void genChmWall2();
    void genChmWall3();
    void genChmWall4(int extend = 0);
    void genPassage1();
    void genPassage2(int choice = 0);
    void genChamber4();
    void genChamber5(int choice = 0);
    void genPassage3 (int choice = 0);
    void genChamber5Bottom(int choice = 0);

    void InsertChamber(vector < vector <int> > &chambers, int index, MapItemType type);
    void InsertDragonHoard(vector < vector <int> > &chambers, int index);
    void InsertBoth(vector <int> &chamber, int row, int col);

public:
    friend class Game;
    GameObject* GetObject(int row, int col) const;
    CellType *Getviews(int row, int col) const;
    void GenerateObject(int row, int col, MapItemType type);
    void Attach(int row, int col, GameObject* obj); // attach a Gameobj to a specific cell
    void Detach(int row, int col);                  // detach a Gameobj from a specific cell  
};



#endif
