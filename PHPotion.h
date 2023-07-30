#ifndef _PH_H_
#define _PH_H_

#include "Potion.h"
#include "cc3klib.h"
class PHPotion : public Potion {
    inline static bool PHReveal = false;
public:
    PHPotion(int row, int col, Map *map);
    ~PHPotion();
    bool IsRevealed() override;
    MapItemType Consume() override;
};

#endif
