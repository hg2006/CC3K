#include "Player.h"

class Vampire : public Player {
public:
    Vampire(int row, int col, string nameNotion = "Vampire", int currentHP = 50, int maxHP = 50, int atk = 25, int def = 25, int gold = 0);
    ~Vampire();
    void attackNotify(string direction) override;
};
