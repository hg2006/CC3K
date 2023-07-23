#include "Orcs.h"
#include <cmath>

Orcs::Orcs(int row, int col, Map *map, std::string nameNotion, int currentHP, int maxHP, int atk, int def) :
    Enemy{row, col, map, nameNotion, currentHP, maxHP, atk, def} {}

Orcs::~Orcs() {}

void Orcs::attackNotify() {
    int var = std::rand() % 2;
    Player *p = map->GetPlayer();
    if (var == 1) {
        if (p->getName() == "Goblin") {
            p->attacked(std::ceil(atk * 1.5));
        } else {
            p->attacked(atk);
        }
    } else {
        //
    }
}
