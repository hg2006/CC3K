#ifndef _VERTICALWALL_H_
#define _VERTICALWALL_H_

#include "cc3klib.h"
#include "Cell.h"
#include "Wall.h"

class VerticalWall: public Wall{

    VerticalWall();
    ~VerticalWall();
    void Render() const override;
    CellType GetType() const override;

};

#endif
