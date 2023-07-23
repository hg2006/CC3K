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
    
    Map();
    ~Map();
    void InitializeMap();
    void RenderMap() const;
    void UpdateMap();

public:
    friend class Game;
    GameObject* GetObject(int row, int col) const;
    CellType *Getviews(int row, int col) const;
    void GenerateObject(int row, int col, MapItemType type);
    void Attach(int row, int col, GameObject* obj); // attach a Gameobj to a specific cell
    void Detach(int row, int col);                  // detach a Gameobj from a specific cell 
    int index_convert(int row, int col) const;
};



#endif
