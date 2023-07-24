#include "Player.h"
#include "cc3klib.h"
#include "Map.h"
#include <vector>

Player::Player(int row, int col, Map *map, MapItemType type, int currentHP, int maxHP, int atk, int def, int gold) :
    BuffedPlayer{row, col, map, type, currentHP, maxHP, atk, def, gold} {}

Player::~Player() {}

void Player::takePotion(const PotionType potion) {
    const int changeHPNum = 10;
    if (potion == PRH) {
        changeHP(changeHPNum);
    } else if (potion == PPH) {
        changeHP(changeHPNum);
    }
}

void Player::attackNotify(const std::string direction) {
    vector<CellType> ct = detect();
    if (direction == "nw") {
        if (ct[0] == ENEMY) {
            map->GetObject(row - 1, col - 1)->attacked(atk);
        }
    } else if (direction == "no") {
        if (ct[1] == ENEMY) {
            map->GetObject(row - 1, col)->attacked(atk);
        }
    } else if (direction == "ne") {
        if (ct[2] == ENEMY) {
            map->GetObject(row - 1, col + 1)->attacked(atk);
        }
    } else if (direction == "we") {
        if (ct[3] == ENEMY) {
            map->GetObject(row, col - 1)->attacked(atk);
        }
    } else if (direction == "ea") {
        if (ct[5] == ENEMY) {
            map->GetObject(row, col + 1)->attacked(atk);
        }
    } else if (direction == "sw") {
        if (ct[6] == ENEMY) {
            map->GetObject(row + 1, col - 1)->attacked(atk);
        }
    } else if (direction == "so") {
        if (ct[7] == ENEMY) {
            map->GetObject(row + 1, col)->attacked(atk);
        }
    } else if (direction == "se") {
        if (ct[8] == ENEMY) {
            map->GetObject(row + 1, col + 1)->attacked(atk);
        }
    }
}

int Player::getAtk() const {
    return atk;
}

int Player::getDef() const {
    return def;
}

void enemyIsKilled() {}
void endOfTurn() {}

