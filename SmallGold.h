#ifndef _SMALLGOLD_H_
#define _SMALLGOLD_H_

#include "Treasure.h"
#include "cc3klib.h"

class SmallGold : public Treasure {
public:
    SmallGold(int row, int col, Map *map);
    ~SmallGold();
    MapItemType Consume() override;
};

#endif
