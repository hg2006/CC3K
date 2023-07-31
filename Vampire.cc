#include "Vampire.h"
#include "Map.h"

Vampire::Vampire(int row, int col, Map *map, MapItemType type, int currentHP, int maxHP, int atk, int def, int gold) :
    Player{row, col, map, type, currentHP, maxHP, atk, def, gold} {}

Vampire::~Vampire() {}

void Vampire::changeHP(const int HP) {
    int tmpHP = currentHP + HP;
    if (tmpHP < 0) {
        currentHP = 0;
        deadNotify();
    } else {
        currentHP = tmpHP;
    }
}

