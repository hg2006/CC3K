#include "Merchant.h"
#include <cmath>

Merchant::Merchant(int row, int col, Map *map, MapItemType type, int currentHP, int maxHP, int atk, int def) :
Enemy{row, col, map, type, currentHP, maxHP, atk, def} {}

Merchant::~Merchant() {}

void Merchant::attacked(const int damage) {
    int deductHP = -1 * std::ceil((1.0 * 100 / (100 + def)) * damage);
    hostile = true;
    changeHP(deductHP);
}

void Merchant::moveDecision() {
    CellType *ct = detect();
    if (hostile) {
        for (int i = 0; i < 9; ++i) {
            if (ct[i] == PLAYER) {
                attackNotify();
                return;
            }
        }
    }

    int i = std::rand() % 9;
    while (ct[i] != ROOM || i == 4)
    {
        i = std::rand() % 9;
    }
    
    if (ct[i] == ROOM) {
        if (i < 3) {
            --row;
            col = col - 1 + i;
        } else if (i > 4) {
            ++row;
            col = col - 1 + (i + 1) % 3;
        } else {
            col = col - 1 + 2 * (i % 3);
        }
    }
}

