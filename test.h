#ifndef _TEST_H_
#define _TEST_H_
#include "cc3klib.h"

class GameObject{
public:
    GameObject* GetObject(){return nullptr;}
    MapItemType GetType(){return DRAGON;}
    CellType GetCellType(){return OBSTACLE;}
    void update(){}
};

class BuffedPlayer{
public:
    BuffedPlayer(): col{0}, row{0} {}
    int col;
    int row;
    int Getx(){return 0;}
    int Gety(){return 0;}
};

#endif
