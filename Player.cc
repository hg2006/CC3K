#include "Player.h"
#include "Map.h"

Player::Player(int row, int col, Map *map, MapItemType type, int currentHP, int maxHP, int atk, int def, int gold) :
    BuffedPlayer{row, col, map, type, currentHP, maxHP, atk, def, gold} {}

Player::~Player() {}

void Player::takePotion(const std::string direction) {
    std::vector<CellType> ct = this->detect();
    GameObject *obj = nullptr;
    if (direction == "nw") {
        if (ct[0] == POTION) {
            obj = map->GetObject(row - 1, col - 1);
        }
    } else if (direction == "no") {
        if (ct[1] == POTION) {
            obj = map->GetObject(row - 1, col);
        }
    } else if (direction == "ne") {
        if (ct[2] == POTION) {
            obj = map->GetObject(row - 1, col + 1);
        }
    } else if (direction == "we") {
        if (ct[3] == POTION) {
            obj = map->GetObject(row, col - 1);
        }
    } else if (direction == "ea") {
        if (ct[5] == POTION) {
            obj = map->GetObject(row, col + 1);
        }
    } else if (direction == "sw") {
        if (ct[6] == POTION) {
            obj = map->GetObject(row + 1, col - 1);
        }
    } else if (direction == "so") {
        if (ct[7] == POTION) {
            obj = map->GetObject(row + 1, col);
        }
    } else if (direction == "se") {
        if (ct[8] == POTION) {
            obj = map->GetObject(row + 1, col + 1);
        }
    }

    if (obj) {
        Potion *p = static_cast<Potion*>(obj);
        const int changeHPNum = 10;
        if (p->IsReveal) {
            // print the name of this potion
        } else {
            // print unknow potion
        }
        MapItemType pt = p->Consume();
        if (pt == RH) {
            changeHP(changeHPNum);
        } else if (pt == PH) {
            changeHP(changeHPNum);
        } else {
            map->takePotion(pt, 5);
        }
    } else {
        // print there's no potion at this position
    }
}

void Player::attackNotify(const std::string direction) {
    std::vector<CellType> ct = this->detect();
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

