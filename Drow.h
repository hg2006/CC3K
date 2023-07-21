#include "Player.h"
#include "cc3klib.h"

class Drow : public Player {
public:
    Drow(int row, int col, string nameNotion = "Drow", int currentHP = 150, int maxHP = 150, int atk = 25, int def = 15, int gold = 0);
    ~Drow();
    void takePotion(const PotionType potion) const override;
};
