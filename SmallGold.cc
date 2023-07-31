
#include "SmallGold.h"
#include "cc3klib.h"

SmallGold::SmallGold(int row, int col, Map *map) :
    Treasure{row, col, map} {}

SmallGold::~SmallGold() {}

MapItemType SmallGold::Consume() {
    detach();
    map->getPlayer()->changeGold(1);
    return SMALLGOLD;
}
