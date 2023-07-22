#include "Dwarf.h"
#include "cc3klib.h"

Dwarf::Dwarf(int row, int col, Map *map, std::string nameNotion, int currentHP, int maxHP, int atk, int def) :
    Enemy{row, col, map, nameNotion, currentHP, maxHP, atk, def} {}

Dwarf::~Dwarf() {}
