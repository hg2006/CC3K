#include "Item.h"

Item::Item(int row, int col, Map *map) :
    GameObject{row, col, map} {}

Item::~Item() {}
