#ifndef _BD_H_
#define _BD_H_

#include "Potion.h"
#include "cc3klib.h"

class BDPotion : public Potion {
    inline static bool BDReveal = false;
public:
    BDPotion(int row, int col, Map *map);
    ~BDPotion();
    bool IsRevealed() override;
    MapItemType Consume() override;
};

#endif
