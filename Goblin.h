#ifndef _GOBLIN_H_
#define _GOBLIN_H_

#include "Player.h"
#include "cc3klib.h"

class Goblin : public Player {
public:
    Goblin(int row, int col, Map *map, MapItemType type = GOBLIN, int currentHP = 110, int maxHP = 110, int atk = 15, int def = 20, int gold = 0);
    ~Goblin();
    void enemyIsKilled() override;
};

#endif
