#ifndef _CELL_H_
#define _CELL_H_

#include "cc3klib.h"

class Cell{
protected:
    GameObject* obj;

    friend class Map;

    Cell();   // defaulted to be nullptr
    virtual ~Cell();
    virtual void Render() const = 0;
    virtual CellType GetType() const = 0;
    GameObject* GetObject() const;
    void Attach(GameObject* obj);
    void Detach();
};

#endif
