#include "VerticalWall.h"
using namespace std;

char VerticalWall:: Render() const{
    return '|';
}

CellType VerticalWall:: GetType() const{
    return OBSTACLE;
}

