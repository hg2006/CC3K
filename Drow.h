#ifndef _DROW_H_
#define _DROW_H_

#include "Player.h"
#include "cc3klib.h"

class Drow : public Player {
public:
    Drow(int row, int col, Map *map, MapItemType type = DROW , int currentHP = 150, int maxHP = 150, int atk = 25, int def = 15, int gold = 0);
    ~Drow();
    void takePotion(const std::string direction) override;
};

#endif
