#include "Treasure.h"

Treasure::Treasure(int row, int col, Map *map) :
    Item(row, col, map) {}

Treasure::~Treasure() {}

bool Treasure::getPickable() {
    return true;
}

void Treasure::setPickable(bool pick) {}
