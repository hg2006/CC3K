#include "Drow.h"
#include "Map.h"
#include "Potion.h"
#include "cc3klib.h"
#include <vector>

Drow::Drow(int row, int col, Map *map, MapItemType type,  int currentHP, int maxHP, int atk, int def, int gold) :
    Player{row, col, map, type, currentHP, maxHP, atk, def, gold} {}

Drow::~Drow() {}

void Drow::takePotion(const std::string direction) {
    std::vector<CellType> ct = this->detect();
    GameObject *obj = nullptr;
    if (direction == "nw") {
        if (ct[0] == POTION) {
            obj = map->GetObject(row - 1, col - 1);
        }
    } else if (direction == "no") {
        if (ct[1] == POTION) {
            obj = map->GetObject(row - 1, col);
        }
    } else if (direction == "ne") {
        if (ct[2] == POTION) {
            obj = map->GetObject(row - 1, col + 1);
        }
    } else if (direction == "we") {
        if (ct[3] == POTION) {
            obj = map->GetObject(row, col - 1);
        }
    } else if (direction == "ea") {
        if (ct[5] == POTION) {
            obj = map->GetObject(row, col + 1);
        }
    } else if (direction == "sw") {
        if (ct[6] == POTION) {
            obj = map->GetObject(row + 1, col - 1);
        }
    } else if (direction == "so") {
        if (ct[7] == POTION) {
            obj = map->GetObject(row + 1, col);
        }
    } else if (direction == "se") {
        if (ct[8] == POTION) {
            obj = map->GetObject(row + 1, col + 1);
        }
    }

    if (obj) {
        Potion *p = static_cast<Potion*>(obj);
        const int changeHPNum = 15;
        if (p->IsReveal) {
            // print the name of this potion
        } else {
            // print unknow potion
        }
        MapItemType pt = p->Consume();
        if (pt == RH) {
            changeHP(changeHPNum);
        } else if (pt == PH) {
            changeHP(changeHPNum);
        } else {
            map->takePotion(pt, 8);
        }
    } else {
        // print there's no potion at this position
    }
}