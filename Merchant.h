#include "Enemy.h"

class Merchant : public Enemy {
    inline static bool hostile = false;
public:
    Merchant(int row, int col, string nameNotion = "Merchant", int currentHP = 30, int maxHP = 30, int atk = 70, int def = 5);
    ~Merchant();
    void attacked(const int damage) override;
    void moveDecision() override;
};
