#include "Map.h"
using namespace std;

void Map::t(){
  vector <int> chamber1;
    for (int i = 240; i < 266; ++i){
        for (int j = 0; j < 4; ++j){
          int coord =i+j*howmanycol;
          GenerateObject(coord/howmanycol, coord%howmanycol, HUMAN);
        }
    }
    vector <int> chamber2;
    for (int i = 276; i < 299; ++i){
        for (int j = 0; j < 4; ++j){
          int coord =i+j*howmanycol;
          GenerateObject(coord/howmanycol, coord%howmanycol, HUMAN);
        }
    }
    for (int i = 457; i < 465; ++i){
        int coord =i;
        GenerateObject(coord/howmanycol, coord%howmanycol, HUMAN);
        GenerateObject(coord/howmanycol+1, coord%howmanycol, HUMAN);
    }
    GenerateObject(544/howmanycol, 544%howmanycol, HUMAN);
    GenerateObject(545/howmanycol, 545%howmanycol, HUMAN);
    GenerateObject(546/howmanycol, 546%howmanycol, HUMAN);
    for (int i = 614; i < 629; ++i){
        for (int j = 0; j < 6; ++j){
            int coord =i+j*howmanycol;
            GenerateObject(coord/howmanycol, coord%howmanycol, HUMAN);
        }
    }
    vector <int> chamber3;
    for (int i = 828; i < 840; ++i){
        for (int j = 0; j < 3; ++j){
            int coord =i+j*howmanycol;
            GenerateObject(coord/howmanycol, coord%howmanycol, HUMAN);
        }
    }
    vector <int> chamber4;
    for (int i = 1189; i < 1210; ++i){
        for (int j = 0; j < 7; ++j){
            int coord =i+j*howmanycol;
            GenerateObject(coord/howmanycol, coord%howmanycol, HUMAN);
        }
    }
    vector <int> chamber5;
    for (int i = 1538; i < 1577; ++i){
        for (int j = 0; j < 3; ++j){
            int coord =i+j*howmanycol;
            GenerateObject(coord/howmanycol, coord%howmanycol, HUMAN);
        }
    }
    for (int i = 1487; i < 1498; ++i){
        for (int j = 0; j < 3; ++j){
            int coord =i-j*howmanycol;
            GenerateObject(coord/howmanycol, coord%howmanycol, HUMAN);
        }
    }
    this->RenderMap();
}
