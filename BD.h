#ifndef _BD_H_
#define _BD_H_

#include "Potion.h"
#include "cc3klib.h"

class BD : public Potion {
    inline static bool BDReveal = false;
public:
    BD();
    ~BD();
    bool IsRevealed() override;
    MapItemType Consume() override;
}

#endif
