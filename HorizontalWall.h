#ifndef _HORIZONTALWALL_H_
#define _HORIZONTALWALL_H_

#include "cc3klib.h"
#include "Cell.h"
#include "Wall.h"

class HorizontalWall: public Wall{

    HorizontalWall();
    ~HorizontalWall();
    void Render() const override;
    CellType GetType() const override;
};

#endif
