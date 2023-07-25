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
