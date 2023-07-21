#include "Player.h"

class Goblin : public Player {
public:
    Goblin(string nameNotion = "Goblin", int currentHP = 110, int maxHP = 110, int Atk = 15, int Def = 20, int gold = 0);
    ~Goblin();
    void enemyIsKilled() override;
};
