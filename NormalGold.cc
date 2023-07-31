
#include "NormalGold.h"
#include "cc3klib.h"

NormalGold::NormalGold(int row, int col, Map *map) :
    Treasure{row, col, map} {}

NormalGold::~NormalGold() {}

MapItemType NormalGold::Consume() {
    detach();
    map->getPlayer()->changeGold(2);
    return NORMALGOLD;
}
