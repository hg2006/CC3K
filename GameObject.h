#include "cc3klib.h"
#include "Map.h"

class GameObject {
protected:
    int row;
    int col;
    Map *map;
public:
    GameObject(int row, int col, Map *map);
    virtual ~GameObject();
    int GetRow();
    int GetCol();
    void SetRow(int row);
    void SetCol(int col);
    virtual void attach();
    virtual void detach();
    GameObject* GetObject();
    CellType GetCellType();
    virtual MapItemType GetType();
};
