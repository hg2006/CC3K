#include "Object.h"


Object::Object(int row, int col) : 
row{row}, col{col} {}
Object::~Object() {}
int Object::getRow() {
    return row;
}

int Object::getCol() {
    return col;
}

void Object::attach() {

}

void Object::detach() {}
