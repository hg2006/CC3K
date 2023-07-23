#include "cc3klib.h"

class Object {
protected:
    int row;
    int col;
public:
    Object(int row, int col);
    virtual ~Object();
    int getRow();
    int getCol();
    virtual void attach();
    virtual void detach();
};
