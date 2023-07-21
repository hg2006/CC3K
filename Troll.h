#include "Player.h"

class Troll : public Player {
public:
    Troll(string nameNotion = "Troll", int currentHP = 120, int maxHP = 120, int Atk = 25, int Def = 15, int gold = 0);
    ~Troll();
    void endOfTurn() override;
};
