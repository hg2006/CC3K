#ifndef _BA_H_
#define _BA_H_

#include "Potion.h"
#include "cc3klib.h"
class BAPotion : public Potion {
    inline static bool BAReveal = false;
public:
    BAPotion(int row, int col, Map *map);
    ~BAPotion();
    bool IsRevealed() override;
    MapItemType Consume() override;
};

#endif
