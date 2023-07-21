#ifndef _STAIR_H_
#define _STAIR_H_

#include "cc3klib.h"
#include "Cell.h"

class Stair: public Cell{

    Stair();
    ~Stair();
    void Render() const override;
    CellType GetType() const override;
};

#endif
