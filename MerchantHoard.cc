
#include "MerchantHoard.h"
#include "cc3klib.h"

MerchantHoard::MerchantHoard(int row, int col, Map *map) :
    Treasure{row, col, map} {}

MerchantHoard::~MerchantHoard() {}

MapItemType MerchantHoard::Consume() {
    detach();
    map->getPlayer()->changeGold(4);
    return MERCHANTHOARD;
}
