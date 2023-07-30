
#include "PHPotion.h"
#include "cc3klib.h"

PHPotion::PHPotion(int row, int col, Map *map) :
    Potion{row, col, map} {}

PHPotion::~PHPotion() {}

bool PHPotion::IsRevealed() {
    return PHReveal;
}

MapItemType PHPotion::Consume() {
    PHReveal = true;
    detach();
    return PH;
}

