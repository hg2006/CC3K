#include "Enemy.h"

class Orcs : public Enemy {
public:
    Orcs(int row, int col, Map *map, MapItemType type = ORCS, int currentHP = 180, int maxHP = 180, int atk = 30, int def = 25);
    ~Orcs();
    void attackNotify() override;
};
