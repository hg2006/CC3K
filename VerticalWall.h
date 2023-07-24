#ifndef _VERTICALWALL_H_
#define _VERTICALWALL_H_

#include "cc3klib.h"
#include "Cell.h"

class VerticalWall: public Cell{
public:
    VerticalWall(){}
    ~VerticalWall(){}
    char Render() const override;
    CellType GetType() const override;

};

#endif
