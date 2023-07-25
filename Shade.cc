#include "Shade.h"
#include "cc3klib.h"

Shade::Shade(int row, int col, Map *map, MapItemType type, int currentHP, int maxHP, int atk, int def, int gold) :
    Player{row, col, map, type, currentHP, maxHP, atk, def, gold} {}

Shade::~Shade() {}
