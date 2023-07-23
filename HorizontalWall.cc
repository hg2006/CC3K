#include "HorizontalWall.h"
using namespace std;

char HorizontalWall:: Render() const{
    return '-';
}

CellType HorizontalWall:: GetType() const{
    return OBSTACLE;
}


