#include "Enemy.h"

class Halfling : Enemy {
public:
    Halfling(int row, int col, string nameNotion = "Halfling", int currentHP = 100, int maxHP = 100, int atk = 15, int def = 20);
    ~Halfling();
    void attacked(const int damage) override;
};
