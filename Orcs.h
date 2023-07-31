#ifndef _ORCS_H_
#define _ORCS_H_

#include "Enemy.h"
#include "BuffedPlayer.h"
#include "cc3klib.h"

class Orcs : public Enemy {
public:
    Orcs(int row, int col, Map *map, MapItemType type = ORCS, int currentHP = 180, int maxHP = 180, int atk = 30, int def = 25);
    ~Orcs();
    void attackNotify() override;
};

#endif
