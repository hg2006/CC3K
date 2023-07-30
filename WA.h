#ifndef _WA_H_
#define _WA_H_

#include "Potion.h"
#include "cc3klib.h"
class WA : public Potion {
    inline static bool WAReveal = false;
public:
    WA();
    ~WA();
    bool IsRevealed() override;
    MapItemType Consume() override;
}

#endif
