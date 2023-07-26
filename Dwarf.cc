#include "Dwarf.h"
#include "Map.h"

Dwarf::Dwarf(int row, int col, Map *map, MapItemType type, int currentHP, int maxHP, int atk, int def) :
    Enemy{row, col, map, type, currentHP, maxHP, atk, def} {}

Dwarf::~Dwarf() {}

void Dwarf::attacked(const int damage) {
    int deductHP = -1 * std::ceil((1.0 * 100 / (100 + def)) * damage);
    changeHP(deductHP);
    if (map->GetPlayer()->GetType() == VAMPIRE) {
        map->GetPlayer()->changeHP(-5);
    }
}
