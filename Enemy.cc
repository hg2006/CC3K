#include "Enemy.h"

Enemy::Enemy(int row, int col, Map *map, std::string nameNotion, int currentHP, int maxHP, int atk, int def) :
    Character{row, col, map, nameNotion, currentHP, maxHP, atk, def} {}

Enemy::~Enemy() {}

void Enemy::deadNotify() {
    map->GetPlayer()->enemyIsKilled();
    map->detach(row, col);
}

void Enemy::attackNotify() {
    CellType *ct = detect();
    int tmpRow;
    int tmpCol;
    for (int i = 0; i < 8; ++i) {
        if (ct[i] == PLAYER) {
            // random to decide whether the attack success here
            int var = std::rand() % 2;
            if (var == 1) {
                map->GetPlayer()->attacked(atk);
            } else {
                // still wait to decide what will happen if the attack missed
            }
            break;
        }
    }
}

void Enemy::moveDecision() {
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
