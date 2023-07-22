#include "Enemy.h"

class Halfling : public Enemy {
public:
    Halfling(int row, int col, Map *map, std::string nameNotion = "Halfling", int currentHP = 100, int maxHP = 100, int atk = 15, int def = 20);
    ~Halfling();
    void attacked(const int damage) override;
};
