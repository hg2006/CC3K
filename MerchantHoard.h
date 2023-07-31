#ifndef _MERCHANTHOARD_H_
#define _MERCHANTHOARD_H_

#include "Treasure.h"
#include "cc3klib.h"

class MerchantHoard : public Treasure {
public:
    MerchantHoard(int row, int col, Map *map);
    ~MerchantHoard();
    MapItemType Consume() override;
};

#endif
