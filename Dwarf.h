#include "Enemy.h"

class Dwarf : public Enemy {
public:
    Dwarf(int row, int col, Map *map, std::string nameNotion = "Dwarf", int currentHP = 100, int maxHP = 100, int atk = 20, int def = 30);
    ~Dwarf();
};
