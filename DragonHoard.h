#ifndef _DRAGONHOARD_H_
#define _DRAGONHOARD_H_

#include "Treasure.h"
#include "cc3klib.h"

class DragonHoard : public Treasure {
    bool pickable = false;
public:
    DragonHoard(int row, int col, Map *map);
    ~DragonHoard();
    MapItemType Consume() override;
    bool getPickable() override;
    void setPickable(bool pick) override;
};

#endif
