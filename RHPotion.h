#ifndef _rH_H_
#define _rH_H_

#include "Potion.h"
#include "cc3klib.h"
class RHPotion : public Potion {
    inline static bool RHReveal = false;
public:
    RHPotion(int row, int col, Map *map);
    ~RHPotion();
    bool IsRevealed() override;
    MapItemType Consume() override;
};

#endif
