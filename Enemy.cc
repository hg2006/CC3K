#include "Enemy.h"
#include "Map.h"

Enemy::Enemy(int row, int col, Map *map, MapItemType type, int currentHP, int maxHP, int atk, int def) :
    Character{row, col, map, type, currentHP, maxHP, atk, def} {}

Enemy::~Enemy() {}

void Enemy::deadNotify() {
    map->GetPlayer()->enemyIsKilled();
    detach();
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
    std::vector<CellType> ct = detect();
    for (int i = 0; i < 9; ++i) {
        if (ct[i] == PLAYER) {
            attackNotify();
            return;
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

CellType Enemy:: GetCellType(){
    return ENEMY;
}
