#include "Enemy.h"

class Human : public Enemy {
public:
    Human(int row, int col, Map *map, std::string nameNotion = "Human", int currentHP = 140, int maxHP = 140, int atk = 20, int def = 20);
    ~Human();
    void deadNotify() override;
};
