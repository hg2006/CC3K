#include "BAPotion.h"
#include "cc3klib.h"

BAPotion::BAPotion(int row, int col, Map *map) :
    Potion{row, col, map} {}

BAPotion::~BAPotion() {}

bool BAPotion::IsRevealed() {
    return BAReveal;
}

MapItemType BAPotion::Consume() {
    BAReveal = true;
    detach();
    return BA;
}

