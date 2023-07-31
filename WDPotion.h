#ifndef _WD_H_
#define _WD_H_

#include "Potion.h"
#include "cc3klib.h"
class WDPotion : public Potion {
    inline static bool WDReveal = false;
public:
    WDPotion(int row, int col, Map *map);
    ~WDPotion();
    bool IsRevealed() override;
    MapItemType Consume() override;
};

#endif
