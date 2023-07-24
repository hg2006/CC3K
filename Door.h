#ifndef _DOOR_H_
#define _DOOR_H_

#include "cc3klib.h"
#include "Cell.h"

class Door: public Cell{
public:
    Door(){}
    ~Door(){}
    char Render() const override;
    CellType GetType() const override;
};

#endif
