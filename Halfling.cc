#include "Halfling.h"

Halfling::Halfling(int row, int col, Map *map, MapItemType type, int currentHP, int maxHP, int atk, int def) :
    Enemy{row, col, map, type, currentHP, maxHP, atk, def} {}

Halfling::~Halfling() {}

void Halfling::attacked(const int damage) {
    int var = std::rand() % 2;
    if (var == 1) {
        int deductHP = -1 * std::ceil((1.0 * 100 / (100 + def)) * damage);
        changeHP(deductHP);
    } else {
        // still wait to decide what will happen if the attack missed
    }
}

