#include "Item.h"

Item::Item(int row, int col, Map *map) :
    row{row}, col{col}, map{map} {}

Item::~Item() {}
