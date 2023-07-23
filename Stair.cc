#include "Stair.h"
using namespace std;

char Stair::Render() const{
    return '/';
}

CellType Stair:: GetType() const{
    return STAIR;
}
