#include "WDPotion.h"
#include "cc3klib.h"

WDPotion::WDPotion(int row, int col, Map *map) :
    Potion{row, col, map} {}

WDPotion::~WDPotion() {}

bool WDPotion::IsRevealed() {
    return WDReveal;
}

MapItemType WDPotion::Consume() {
    WDReveal = true;
    detach();
    return WD;
}

