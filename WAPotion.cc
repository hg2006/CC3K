#include "WAPotion.h"
#include "cc3klib.h"

WAPotion::WAPotion(int row, int col, Map *map) :
    Potion{row, col, map} {}

WAPotion::~WAPotion() {}

bool WAPotion::IsRevealed() {
    return WAReveal;
}

MapItemType WAPotion::Consume() {
    WAReveal = true;
    detach();
    return WA;
}

