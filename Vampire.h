#include "Player.h"

class Vampire : public Player {
public:
    Vampire(string nameNotion = "Vampire", int currentHP = 50, int maxHP = 50, int Atk = 25, int Def = 25, int gold = 0);
    ~Vampire();
    void attackNotify(string direction) override;
};
