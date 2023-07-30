#ifndef _WD_H_
#define _WD_H_

#include "Potion.h"
#include "cc3klib.h"
class WD : public Potion {
    inline static bool WDReveal = false;
public:
    WD();
    ~WD();
    bool IsRevealed() override;
    MapItemType Consume() override;
}

#endif
