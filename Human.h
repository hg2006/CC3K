#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "Enemy.h"
#include "cc3klib.h"

class Human:public Enemy {
public:
    Human(int row, int col, Map *map, MapItemType type = HUMAN, int currentHP = 140, int maxHP = 140, int atk = 20, int def = 20);
    ~Human();
    void deadNotify() override;
};

#endif
