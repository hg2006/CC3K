#ifndef _ITEM_H_
#define _ITEM_H_

#include "GameObject.h"
#include "cc3klib.h"

class Item : public GameObject{
public:
    Item(int row, int col, Map *map);
    virtual ~Item();
    virtual MapItemType Consume() = 0;
};

#endif
