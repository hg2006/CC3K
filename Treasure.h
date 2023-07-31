#ifndef _TREASURE_H_
#define _TREASURE_H_

#include "Item.h"

class Treasure : public Item {
public:
    Treasure();
    virtual ~Treasure();
    virtual MapItemType Consume() = 0;
};

#endif
