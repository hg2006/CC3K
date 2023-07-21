#ifndef _WALL_H_
#define _WALL_H_

#include "cc3klib.h"
#include "Cell.h"

class Wall: public Cell{

    Wall();
    virtual ~Wall();
    // Render still virtual
    CellType GetType() const override;
};

#endif
