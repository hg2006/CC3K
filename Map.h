#ifndef _MAP_H_
#define _MAP_H_

#include "cc3klib.h"

#include "Cell.h"
#include "Room.h"
#include "Passage.h"
#include "Door.h"
#include "Blank.h"
#include "Wall.h"
#include "VerticalWall.h"
#include "HorizontalWall.h"
#include "Stair.h"


class Map{
    vector<Cell *> tiles;   // A vector of 1975 elements

    Map();
    ~Map();
    void InitializeMap();
    void RenderMap() const;
    void UpdateMap();

public:
    friend class Game;
    GameObejct* GetObject(int row, int col);
    CellType Getviews(int row, int col);
    void Attach(int row, int col, GameObject* obj); // attach a Gameobj to a specific cell
    void Detach(int row, int col);                  // detach a Gameobj from a specific cell  
};



#endif
