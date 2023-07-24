#include "Troll.h"
#include "cc3klib.h"

Troll::Troll(int row, int col, Map *map, MapItemType type, int currentHP, int maxHP, int atk, int def, int gold) :
    Player{row, col, map, type, currentHP, maxHP, atk, def, gold} {}

Troll::~Troll() {}

void Troll::endOfTurn() {
    changeHP(5);
}
