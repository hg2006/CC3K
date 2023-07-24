#include "Blank.h"
using namespace std;

char Blank:: Render() const{
    return ' ';
}

CellType Blank:: GetType() const{
    return OBSTACLE;
}

