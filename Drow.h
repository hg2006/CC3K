#include "Player.h"
#include "cc3klib.h"

class Drow : public Player {
public:
    Drow(string nameNotion = "Drow", int currentHP = 150, int maxHP = 150, int Atk = 25, int Def = 15, int gold = 0);
    ~Drow();
    void takePotion(const PotionType potion) const override;
};
