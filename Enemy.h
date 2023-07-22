#include "Character.h"

class Enemy : public Character {
public:
    Enemy(int row, int col, Map *map, std::string nameNotion = "", int currentHP = 0, int maxHP = 0, int atk = 0, int def = 0);
    virtual ~Enemy();
    virtual void deadNotify() override;
    virtual void attackNotify() override;
    virtual void attacked(const int damage) override;
    virtual void moveDecision();
};
