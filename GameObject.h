#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include "cc3klib.h"
class Map;

class GameObject{
protected:
    int row;
    int col;
    Map *map;
public:
    GameObject(int row, int col, Map *map);
    virtual ~GameObject();
    int GetRow();
    int GetCol();
    void SetRow(int row);
    void SetCol(int col);
    virtual void attach();
    virtual void detach();
    GameObject* GetObject();
    virtual CellType GetCellType();
    virtual MapItemType GetType() = 0; 
    virtual void attacked(const int damage) = 0;
    virtual void moveDecision(){};
    void setMap(Map *newMap);
};

#endif
