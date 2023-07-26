#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Character.h"
#include "BuffedPlayer.h"

class Enemy : public Character {
public:
    Enemy(int row, int col, Map *map, MapItemType type, int currentHP = 0, int maxHP = 0, int atk = 0, int def = 0);
    virtual ~Enemy() = 0;
    virtual void deadNotify() override;
    virtual void attackNotify() override;
    // virtual void attacked(const int damage) override;
    virtual void moveDecision();
    CellType GetCellType() override;
    virtual void attacked(const int damage) override;
};

#endif
