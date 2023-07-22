#include "Player.h"
#include "cc3klib.h"

class Troll : public Player {
public:
    Troll(int row, int col, Map *map, std::string nameNotion = "Troll", int currentHP = 120, int maxHP = 120, int atk = 25, int def = 15, int gold = 0);
    ~Troll();
    void endOfTurn() override;
};
