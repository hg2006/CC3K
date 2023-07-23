#include "Enemy.h"

Enemy::Enemy(int row, int col, Map *map, std::string nameNotion, int currentHP, int maxHP, int atk, int def) :
    Character{row, col, map, nameNotion, currentHP, maxHP, atk, def} {}

Enemy::~Enemy() {}

void Enemy::deadNotify() {
    map->GetPlayer()->enemyIsKilled();
    map->detach(row, col);
}

void Enemy::attackNotify() {
    // random to decide whether the attack success here
    int var = std::rand() % 2;
    if (var == 1) {
        map->GetPlayer()->attacked(atk);
    } else {
        // still wait to decide what will happen if the attack missed
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
