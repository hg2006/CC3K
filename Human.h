#include "Enemy.h"

class Human : Enemy {
public:
    Human(int row, int col, string nameNotion = "Human", int currentHP = 140, int maxHP = 140, int atk = 20, int def = 20);
    ~Human();
    void deadNotify() override;
};
