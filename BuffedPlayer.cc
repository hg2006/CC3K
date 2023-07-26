#include "BuffedPlayer.h"

BuffedPlayer::BuffedPlayer(int row, int col, Map *map, MapItemType type, int currentHP, int maxHP, int atk, int def, int gold) :
    Character{row, col, map, type, currentHP, maxHP, atk, def}, gold {gold} {}

BuffedPlayer::~BuffedPlayer() {}

void BuffedPlayer::takePotion(const PotionType potion) {}

int BuffedPlayer::getAtk() const {
    return atk;
}

int BuffedPlayer::getDef() const {
    return def;
}

void BuffedPlayer::attackNotify(const std::string direction) {}

void BuffedPlayer::moveDecision(std::string behaviour) {
    std::vector<CellType> ct = detect();
    if (behaviour == "nw") {
        if (ct[0] == ROOM || ct[0] == PASSAGE || ct[0] == DOOR || ct[0] == STAIR) {
            --col;
            --row;
        } 
        // else if (ct[0] == TREASURE) {
        //     map->GetObject(col - 1, row - 1)->Consume(); // ??? depends on the implementation of consume in treasure
        // }
    } else if (behaviour == "no") {
        if (ct[1] == ROOM || ct[1] == PASSAGE || ct[1] == DOOR || ct[1] == STAIR) {
            --row;
        }
    } else if (behaviour == "ne") {
        if (ct[2] == ROOM || ct[2] == PASSAGE || ct[2] == DOOR || ct[2] == STAIR) {
            ++col;
            --row;
        }
    } else if (behaviour == "we") {
        if (ct[3] == ROOM || ct[3] == PASSAGE || ct[3] == DOOR || ct[3] == STAIR) {
            --col;
        }
    } else if (behaviour == "ea") {
        if (ct[5] == ROOM || ct[5] == PASSAGE || ct[5] == DOOR || ct[5] == STAIR) {
            ++col;
        }
    } else if (behaviour == "sw") {
        if (ct[6] == ROOM || ct[6] == PASSAGE || ct[6] == DOOR || ct[6] == STAIR) {
            --col;
            ++row;
        }
    } else if (behaviour == "so") {
        if (ct[7] == ROOM || ct[7] == PASSAGE || ct[7] == DOOR || ct[7] == STAIR) {
            ++row;
        }
    } else if (behaviour == "se") {
        if (ct[8] == ROOM || ct[8] == PASSAGE || ct[8] == DOOR || ct[8] == STAIR) {
            ++col;
            ++row;
        }
    }
}

void BuffedPlayer::enemyIsKilled() {}

void BuffedPlayer::endOfTurn() {}

void BuffedPlayer::changeGold(int goldNum) {
    gold += goldNum;
}

int BuffedPlayer::getGold() {
    return gold;
}

int BuffedPlayer::getScore() {
    return gold;
}

