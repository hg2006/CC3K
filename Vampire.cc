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

void Vampire::attackNotify(std::string direction) {
    std::vector<CellType> ct = detect();
    GameObject *obj = nullptr;
    if (direction == "nw") {
        if (ct[0] == ENEMY) {
            obj = map->GetObject(row - 1, col - 1);
        }
    } else if (direction == "no") {
        if (ct[1] == ENEMY) {
            obj = map->GetObject(row - 1, col);
        }
    } else if (direction == "ne") {
        if (ct[2] == ENEMY) {
            obj = map->GetObject(row - 1, col + 1);
        }
    } else if (direction == "we") {
        if (ct[3] == ENEMY) {
            obj = map->GetObject(row, col - 1);
        }
    } else if (direction == "ea") {
        if (ct[5] == ENEMY) {
            obj = map->GetObject(row, col + 1);
        }
    } else if (direction == "sw") {
        if (ct[6] == ENEMY) {
            obj= map->GetObject(row + 1, col - 1);
        }
    } else if (direction == "so") {
        if (ct[7] == ENEMY) {
            obj= map->GetObject(row + 1, col);
        }
    } else if (direction == "se") {
        if (ct[8] == ENEMY) {
            obj = map->GetObject(row + 1, col + 1);
        }
    }

    if (obj != nullptr) {
        obj->attacked(atk);
        if (obj->GetType() == DWARF) {
            changeHP(-5);
        } else {
            changeHP(5);
        }
    }
}
