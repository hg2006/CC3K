#ifndef _DWARF_H_
#define _DWARF_H_

#include "Enemy.h"
#include "cc3klib.h"

class Dwarf : public Enemy {
public:
    Dwarf(int row, int col, Map *map, MapItemType type = DWARF, int currentHP = 100, int maxHP = 100, int atk = 20, int def = 30);
    ~Dwarf();
    void attacked(const int damage) override;
};

#endif
