#include "Player.h"
#include "cc3klib.h"

Player::Player(int row, int col, Map *map, std::string nameNotion, int currentHP, int maxHP, int atk, int def, int gold) :
    BuffedPlayer{row, col, map, nameNotion, currentHP, maxHP, atk, def, gold} {}

Player::~Player();

void Player::takePotion(const PotionType potion) {
    if (potion == PRH) {
        changeHP(10);
    } else if (potion == PPH) {
        changeHP(-10);
    }
}

void Player::attackNotify(const std::string direction) {
    CellType *ct = detect();
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
        if (ct[4] == ENEMY) {
            map->GetObject(row, col + 1)->attacked(atk);
        }
    } else if (direction == "sw") {
        if (ct[5] == ENEMY) {
            map->GetObject(row + 1, col - 1)->attacked(atk);
        }
    } else if (direction == "so") {
        if (ct[6] == ENEMY) {
            map->GetObject(row + 1, col)->attacked(atk);
        }
    } else if (direction == "se") {
        if (ct[7] == ENEMY) {
            map->GetObject(row + 1, col + 1)->attacked(atk);
        }
    }
}

int Player::getAtk() {
    return atk;
}

int Player::getDef() {
    return def;
}

void enemyIsKilled() {}
void endOfTurn() {}

