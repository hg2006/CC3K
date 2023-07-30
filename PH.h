#ifndef _PH_H_
#define _PH_H_

#include "Potion.h"
#include "cc3klib.h"
class PH : public Potion {
    inline static bool PHReveal = false;
public:
    PH();
    ~PH();
    bool IsRevealed() override;
    MapItemType Consume() override;
}

#endif
