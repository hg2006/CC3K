#include "Room.h"
using namespace std;

char Room:: Render() const{
    GameObject* object = this->GetObject();
    
    if(object){
        MapItemType type = object->GetType();
        switch (type){
            case HUMAN:
                return 'H';
            case DWARF:
                return 'D';
            case ELF:
                return 'E';
            case ORCS:
                return 'O';
            case MERCHANT:
                return 'M';
            case DRAGON:
                return 'd';
            case HALFLING:
                return 'h';
            case SMALLGOLD:
            case NORMALGOLD:
            case MERCHANTHOARD:
                return 'G';
            case DRAGONHOARD:
                return 'R';
            case BA:
            case BD:
            case WA:
            case WD:
            case RH:
            case PH:
                return 'P';
        }
    }else return '.';
}

CellType Room:: GetType() const{
    // GetType will never return a player type
    GameObject* object = this->GetObject();
    if(object) return object->GetCellType(); /*required such fcn*/
    else return ROOM;
}

