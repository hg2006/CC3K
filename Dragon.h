#include "Enemy.h"
#include "DragonHoard.h"

class Dragon : Enemy {
    DragonHoard *hoard;
public:
    Dragon(int row, int col, string nameNotion = "Dragon", int currentHP = 150, int maxHP = 150, int atk = 20, int def = 20, DragonHoard *hoard);
    ~Dragon();
    void attackNotify() override;
    void moveDecision(string behaviour) override;
};
