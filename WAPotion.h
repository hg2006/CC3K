#ifndef _WA_H_
#define _WA_H_

#include "Potion.h"
#include "cc3klib.h"
class WAPotion : public Potion {
    inline static bool WAReveal = false;
public:
    WAPotion(int row, int col, Map *map);
    ~WAPotion();
    bool IsRevealed() override;
    MapItemType Consume() override;
};

#endif
