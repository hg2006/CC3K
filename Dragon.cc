#include "Dragon.h"
#include "DragonHoard.h"

Dragon::Dragon(int row, int col, Map *map, MapItemType type, int currentHP, int maxHP, int atk, int def, DragonHoard *hoard) :
    Enemy{row, col, map, type, currentHP, maxHP, atk, def}, hoard{hoard} {}

Dragon::~Dragon() {}

void Dragon::deadNotify() {
    map->GetPlayer()->enemyIsKilled();
    hoard->SetPickable(true);
    detach()
}

void Dragon::moveDecision() {
    CellType *ct = detect();
    for (int i = 0; i < 9; ++i) {
        if (ct[i] == PLAYER) {
            attackNotify();
            return;
        }
    }
}
