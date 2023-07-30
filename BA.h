#ifndef _BA_H_
#define _BA_H_

#include "Potion.h"
#include "cc3klib.h"
class BA : public Potion {
    inline static bool BAReveal = false;
public:
    BA();
    ~BA();
    bool IsRevealed() override;
    MapItemType Consume() override;
}

#endif
