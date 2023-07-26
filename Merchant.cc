#include "Merchant.h"
#include "Map.h"

Merchant::Merchant(int row, int col, Map *map, MapItemType type, int currentHP, int maxHP, int atk, int def) :
Enemy{row, col, map, type, currentHP, maxHP, atk, def} {}

Merchant::~Merchant() {}

void Merchant::attacked(const int damage) {
    int deductHP = -1 * std::ceil((1.0 * 100 / (100 + def)) * damage);
    hostile = true;
    changeHP(deductHP);
    if (map->GetPlayer()->GetType() == VAMPIRE) {
        map->GetPlayer()->changeHP(5);
    }
}

void Merchant::moveDecision() {
    std::vector<CellType> ct = detect();
    if (hostile) {
        for (int i = 0; i < 9; ++i) {
            if (ct[i] == PLAYER) {
                attackNotify();
                return;
            }
        }
    }
    map->Detach(row, col);
    int i = std::rand() % 9;
    while (ct[i] != ROOM || i == 4)
    {
        i = std::rand() % 9;
    }
    
    if (ct[i] == ROOM) {
        if (i < 3) {
            --row;
        } else if (i > 5) {
            ++row;
        }
        col = col - 1 + i % 3;
    }
    map->Attach(row, col, this);
}

