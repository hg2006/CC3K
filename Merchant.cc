#include "Merchant.h"

Merchant::Merchant(int row, int col, Map *map, std::string nameNotion, int currentHP, int maxHP, int atk, int def) :
Enemy{row, col, map, nameNotion, currentHP, maxHP, atk, def} {}

Merchant::~Merchant() {}

void Merchant::attacked(const int damage) {
    int deductHP = -1 * ceil((1.0 * 100 / (100 + def)) * damage);
    hostile = true;
    changeHP(deductHP);
}

void Merchant::moveDecision() {
    if (hostile) {
        CellType *ct = detect();
        for (int i = 0; i < 8; ++i) {
            if (ct[i] == PLAYER) {
                attackNotify();
                return;
            }
        }
    }
    // random to decide where the enemy is gonna go to
    int var = std::rand() % 8;
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

