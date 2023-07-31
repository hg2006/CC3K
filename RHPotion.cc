#include "RHPotion.h"
#include "cc3klib.h"

RHPotion::RHPotion(int row, int col, Map *map) :
    Potion{row, col, map} {}

RHPotion::~RHPotion() {}

bool RHPotion::IsRevealed() {
    return RHReveal;
}

MapItemType RHPotion::Consume() {
    RHReveal = true;
    detach();
    return RH;
}

