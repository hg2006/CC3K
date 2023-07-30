#ifndef _TROLL_H_
#define _TROLL_H_
#include "Player.h"
#include "cc3klib.h"

class Troll : public Player {
public:
    Troll(int row, int col, Map *map, MapItemType type = TROLL,  int currentHP = 120, int maxHP = 120, int atk = 25, int def = 15, int gold = 0);
    ~Troll();
    void endOfTurn() override;
};

#endif
