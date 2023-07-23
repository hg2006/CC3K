#include "Enemy.h"
#include "DragonHoard.h"

class Dragon : public Enemy {
    DragonHoard *hoard;
public:
    Dragon(int row, int col, Map *map, std::string nameNotion = "Dragon", int currentHP = 150, int maxHP = 150, int atk = 20, int def = 20, DragonHoard *hoard = nullptr);
    ~Dragon();
    void deadNotify() override;
    void moveDecision() override;
};
