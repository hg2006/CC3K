#include "Vampire.h"
#include "cc3klib.h"

Vampire::Vampire(int row, int col, Map *map, std::string nameNotion, int currentHP, int maxHP, int atk, int def, int gold) :
    Player{row, col, map, nameNotion, currentHP, maxHP, atk, def, gold} {}

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
    CellType *ct = detect();
    if (direction == "nw") {
        if (ct[0] == ENEMY) {
            map->GetObject(row - 1, col - 1)->attacked(atk);
            changeHP(5);
        }
    } else if (direction == "no") {
        if (ct[1] == ENEMY) {
            map->GetObject(row - 1, col)->attacked(atk);
            changeHP(5);
        }
    } else if (direction == "ne") {
        if (ct[2] == ENEMY) {
            map->GetObject(row - 1, col + 1)->attacked(atk);
            changeHP(5);
        }
    } else if (direction == "we") {
        if (ct[3] == ENEMY) {
            map->GetObject(row, col - 1)->attacked(atk);
            changeHP(5);
        }
    } else if (direction == "ea") {
        if (ct[4] == ENEMY) {
            map->GetObject(row, col + 1)->attacked(atk);
            changeHP(5);
        }
    } else if (direction == "sw") {
        if (ct[5] == ENEMY) {
            map->GetObject(row + 1, col - 1)->attacked(atk);
            changeHP(5);
        }
    } else if (direction == "so") {
        if (ct[6] == ENEMY) {
            map->GetObject(row + 1, col)->attacked(atk);
            changeHP(5);
        }
    } else if (direction == "se") {
        if (ct[7] == ENEMY) {
            map->GetObject(row + 1, col + 1)->attacked(atk);
            changeHP(5);
        }
    }
}
