#include "Passage.h"
using namespace std;

char Passage:: Render() const{
    return '#';
}

CellType Passage:: GetType() const{
    return PASSAGE;
}
