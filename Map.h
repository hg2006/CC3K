#ifndef _MAP_H_
#define _MAP_H_

#include "cc3klib.h"
class BuffedPlayer;
class Decorator;

class Map{
    std::vector < std::unique_ptr<Cell>> tiles;   // A vector of 1975 elements
    std::vector <std::unique_ptr<GameObject>> objects;
    std::vector <std::unique_ptr<Decorator>> decorators;
    BuffedPlayer *player;
    const int howmanyrow = 25;
    const int howmanycol = 79;
    int playerrow = 0;
    int playercol = 0;

    Map(BuffedPlayer *p);
    ~Map();
    void InitializeMap();
    void RenderMap() const;
    void UpdateMap();

    void InsertChamber(std::vector < std::vector <int> > &chambers, int index, MapItemType type);
    void InsertDragonHoard(std::vector < std::vector <int> > &chambers, int index);
    void InsertBoth(std::vector <int> &chamber, int row, int col);

    void genBoarderLine();
    void genBlankLine();
    void genChamber1(int choice = 0);
    void genGap1();
    void genChamber2(int choice = 0);
    void genChamber2Bottom();
    void genChamber3();
    void genGap2();
    void genGap3();
    void genChmWall(int offset = 0);
    void genChmWall2();
    void genChmWall3();
    void genChmWall4(int extend = 0);
    void genPassage1();
    void genPassage2(int choice = 0);
    void genChamber4(int choice = 0);
    void genChamber5(int choice = 0);
    void genPassage3 (int choice = 0);
    void genChamber5Bottom(int choice = 0);

    int index_convert(int row, int col) const;


public:
    friend class Game;
    BuffedPlayer *GetPlayer(){return player;}
    void TakePotion(MapItemType po, int amount);
    GameObject* GetObject(int row, int col) const;
    std::vector <CellType> GetViews(int row, int col) const;
    void GenerateObject(int row, int col, MapItemType type);
    void Attach(int row, int col, GameObject* obj); // attach a Gameobj to a specific cell
    void Detach(int row, int col);                  // detach a Gameobj from a specific cell 
};



#endif
