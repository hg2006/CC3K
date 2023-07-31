#include "Enemy.h"
#include "Map.h"
#include "SmallGold.h"
#include "NormalGold.h"

Enemy::Enemy(int row, int col, Map *map, MapItemType type, int currentHP, int maxHP, int atk, int def) :
    Character{row, col, map, type, currentHP, maxHP, atk, def} {}

Enemy::~Enemy() {}

void Enemy::deadNotify() {
    detach();
    int var = std::rand() % 2;
    if (var == 1) {
        SmallGold *SGold = new SmallGold(row, col, map);
        map->Attach(SGold);
    } else {
        NormalGold *NGold = new NormalGold(row, col, map);
        map->Attach(NGold);
    }
    map->GetPlayer()->enemyIsKilled();
}

void Enemy::attacked(const int damage) {
    int deductHP = -1 * std::ceil((1.0 * 100 / (100 + def)) * damage);
    changeHP(deductHP);
    if (map->GetPlayer()->GetType() == VAMPIRE) {
        map->GetPlayer()->changeHP(5);
    }
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

CellType Enemy:: GetCellType(){
    return ENEMY;
}
