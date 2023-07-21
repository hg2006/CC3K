#include "Enemy.h"

class Dragon : Enemy {
    DragonHoard *hoard;
public:
    Dragon(int row, int col, string nameNotion = "Dragon", int currentHP = 150, int maxHP = 150, int atk = 20, int def = 20, DragonHoard *hoard = nullptr);
    ~Dragon();
    void attackNotify() override;
    void moveDecision() override;
};
