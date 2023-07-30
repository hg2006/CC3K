#ifndef _rH_H_
#define _rH_H_

#include "Potion.h"
#include "cc3klib.h"
class RH : public Potion {
    inline static bool RHReveal = false;
public:
    RH();
    ~RH();
    bool IsRevealed() override;
    MapItemType Consume() override;
}

#endif
