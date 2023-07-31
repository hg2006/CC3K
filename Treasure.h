#ifndef _TREASURE_H_
#define _TREASURE_H_

#include "Item.h"
#include "cc3klib.h"

class Treasure : public Item {
public:
    Treasure(int row, int col, Map *map);
    virtual ~Treasure();
    virtual MapItemType Consume() = 0;
    virtual bool getPickable();
    virtual void setPickable(bool pick);
};

#endif
