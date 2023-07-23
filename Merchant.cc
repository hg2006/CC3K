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
        // random to decide where the enemy is gonna go to
        row += std::rand() % 3 - 1;
        col += std::rand() % 3 - 1;
    }
}

