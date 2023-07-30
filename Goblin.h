#include "Player.h"

class Goblin : public Player {
public:
    Goblin(int row, int col, string nameNotion = "Goblin", int currentHP = 110, int maxHP = 110, int atk = 15, int def = 20, int gold = 0);
    ~Goblin();
    void enemyIsKilled() override;
};
