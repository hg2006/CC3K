#include "cc3klib.h"

class GameObject {
protected:
    int row;
    int col;
    Map *map;
public:
    GameObject(int row, int col, Map *map);
    virtual ~GameObject();
    int getRow();
    int getCol();
    virtual void attach();
    virtual void detach();
};
