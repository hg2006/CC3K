#include "Enemy.h"

class Elf : Enemy {
public:
    Elf(int row, int col, string nameNotion = "Elf", int currentHP = 140, int maxHP = 140, int atk = 30, int def = 10);
    ~Elf();
    void attackNotify() override;
};
