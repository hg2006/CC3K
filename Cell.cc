#include "Cell.h"
using namespace std;

Cell:: Cell(): obj{nullptr}
{}

Cell:: ~Cell(){}

GameObject* Cell:: GetObject() const{
    return obj;
}

void Cell:: SetObject(GameObject* obj){
   this->obj = obj; 
}

void Cell:: Attach(GameObject* obj){
    this->obj = obj;
}

void Cell:: Detach(){
    this->obj = nullptr;
}

char Cell:: Render1(){
    GameObject* object = this->GetObject();
    
    if(object){
        MapItemType type = HUMAN;
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
    }else this->Render();
}
