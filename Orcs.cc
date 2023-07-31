#include "Orcs.h"
#include "Map.h"
#include <cmath>

Orcs::Orcs(int row, int col, Map *map, MapItemType type, int currentHP, int maxHP, int atk, int def) :
    Enemy{row, col, map, type, currentHP, maxHP, atk, def} {}

Orcs::~Orcs() {}

void Orcs::attackNotify() {
    int var = std::rand() % 2;
    BuffedPlayer *p = map->GetPlayer();
    if (var == 1) {
        if (p->GetType() == GOBLIN) {
            p->attacked(std::ceil(atk * 1.5));
        } else {
            p->attacked(atk);
        }
    } else {
        // 
    }
}
