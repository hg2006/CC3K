#ifndef _NORMALGOLD_H_
#define _NORMALGOLD_H_

#include "Treasure.h"
#include "cc3klib.h"

class NormalGold : public Treasure {
public:
    NormalGold(int row, int col, Map *map);
    ~NormalGold();
    MapItemType Consume() override;
};

#endif
