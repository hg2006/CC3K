#ifndef _POTION_H_
#define _POTION_H_

#include "Item.h"

class Potion : public Item {
public:
    Potion(int row, int col, Map *map);
    virtual ~Potion();
    virtual bool IsRevealed();
};

#endif
