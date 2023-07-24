#include "Elf.h"
#include "BuffedPlayer.h"

Elf::Elf(int row, int col, Map *map, MapItemType type, int currentHP, int maxHP, int atk, int def) :
    Enemy{row, col, map, type, currentHP, maxHP, atk, def} {}

Elf::~Elf() {}

void Elf::attackNotify() {
    // random to decide whether the attack success here
    int var = std::rand() % 2;
    int var2 = std::rand() % 2;
    BuffedPlayer *p = map->GetPlayer();
    if (var == 1) {
        p->attacked(atk);
    } else {
        // still wait to decide what will happen if the attack missed
    }
    if (p->GetType() != DROW) {
        if (var2 == 1) {
            p->attacked(atk);
        } else {

        }
    }
}
