#ifndef _PASSAGE_H_
#define _PASSAGE_H_

#include "cc3klib.h"
#include "Cell.h"

class Passage: public Cell{

    Passage(){};
    ~Passage(){};
    char Render() const override;
    CellType GetType() const override;
};

#endif
