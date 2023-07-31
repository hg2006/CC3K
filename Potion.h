#ifndef _POTION_H_
#define _POTION_H_

#include "Item.h"

class Potion : public Item {
public:
    Potion();
    virtual ~Potion();
    virtual bool IsRevealed();
}

#endif
