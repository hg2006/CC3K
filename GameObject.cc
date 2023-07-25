#include "GameObject.h"
#include "Map.h"

GameObject::GameObject(int row, int col, Map *map) : 
    row{row}, col{col}, map{map} {}

GameObject::~GameObject() {}

int GameObject::GetRow() {
    return row;
}

int GameObject::GetCol() {
    return col;
}

void GameObject::SetRow(int row) {
    this->row = row;
}

void GameObject::SetCol(int col) {
    this->col = col;
}

void GameObject::attach() {
    map->Attach(row, col, this);
}

void GameObject::detach() {
    map->Detach(row, col);
}

GameObject* GameObject::GetObject(){return this;}

CellType GetCellType() {return OBSTACLE;}

MapItemType GameObject::GetType() {return HUMAN;}
