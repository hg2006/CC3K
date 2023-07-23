#ifndef _HORIZONTALWALL_H_
#define _HORIZONTALWALL_H_

#include "cc3klib.h"
#include "Cell.h"

class HorizontalWall: public Cell{

    HorizontalWall(){};
    ~HorizontalWall(){};
    char Render() const override;
    CellType GetType() const override;
};

#endif
