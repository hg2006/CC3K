#ifndef _DRAGON_H_
#define _DRAGON_H_

#include "Enemy.h"
#include "cc3klib.h"
#include "DragonHoard.h"
class DragonHoard;

class Dragon : public Enemy {
    DragonHoard *hoard;
public:
    Dragon(int row, int col, Map *map, MapItemType type = DRAGON, int currentHP = 150, int maxHP = 150, int atk = 20, int def = 20, DragonHoard *hoard = nullptr);
    ~Dragon();
    void deadNotify() override;
    void moveDecision() override;
};

#endif
