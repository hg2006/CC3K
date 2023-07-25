#include "Player.h"
#include "cc3klib.h"

class Shade : public Player {
public:
    Shade(int row, int col, Map *map, MapItemType type = SHADE, int currentHP = 125, int maxHP = 125, int atk = 25, int def = 25,  int gold = 0);
    ~Shade();
};
