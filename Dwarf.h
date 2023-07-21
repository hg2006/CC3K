#include "Enemy.h"

class Dwarf : Enemy {
public:
    Dwarf(int row, int col, string nameNotion = "Dwarf", int currentHP = 100, int maxHP = 100, int atk = 20, int def = 30);
    ~Dwarf();
};
