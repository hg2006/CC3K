#include "Player.h"
#include "cc3klib.h"

class Vampire : public Player {
public:
    Vampire(int row, int col, Map *map, MapItemType type = VAMPIRE, int currentHP = 50, int maxHP = 50, int atk = 25, int def = 25, int gold = 0);
    ~Vampire();
    void changeHP(const int HP);
    void attackNotify(std::string direction) override;
};
