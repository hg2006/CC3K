#include "Door.h"
using namespace std;

char Door:: Render() const{
    return '+';
}

CellType Door:: GetType() const{
    return  DOOR;
}

