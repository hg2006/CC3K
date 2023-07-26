#include "Dwarf.h"

Dwarf::Dwarf(int row, int col, Map *map, MapItemType type, int currentHP, int maxHP, int atk, int def) :
    Enemy{row, col, map, type, currentHP, maxHP, atk, def} {}

Dwarf::~Dwarf() {}
