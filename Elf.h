#ifndef _ELF_H_
#define _ELF_H_

#include "Enemy.h"
#include "BuffedPlayer.h"
#include "cc3klib.h"

class Elf : public Enemy {
public:
    Elf(int row, int col, Map *map, MapItemType type = ELF, int currentHP = 140, int maxHP = 140, int atk = 30, int def = 10);
    ~Elf();
    void attackNotify() override;
};

#endif
