#include "Enemy.h"

class Orcs : Enemy {
public:
    Orcs(int row, int col, string nameNotion = "Orcs", int currentHP = 180, int maxHP = 180, int atk = 30, int def = 25);
    ~Orcs();
    void attacked(const int damage) override;
};
