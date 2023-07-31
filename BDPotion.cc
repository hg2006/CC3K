#include "BDPotion.h"
#include "cc3klib.h"

BDPotion::BDPotion(int row, int col, Map *map) :
    Potion{row, col, map} {}

BDPotion::~BDPotion() {}

bool BDPotion::IsRevealed() {
    return BDReveal;
}

MapItemType BDPotion::Consume() {
    BDReveal = true;
    detach();
    return BD;
}

