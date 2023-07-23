#include "Map.h"
using namespace std;

void Map::t(){
  vector <int> chamber1;
    for (int i = 240; i < 267; ++i){
        for (int j = 0; j < 4; ++j){
          int coord =i+j*howmanycol;
          GenerateObject(coord/howmanycol, coord/howmanycol, HUMAN);
        }
    }
    vector <int> chamber2;
    for (int i = 277; i < 300; ++i){
        for (int j = 0; j < 4; ++j){
          int coord =i+j*howmanycol;
          GenerateObject(coord/howmanycol, coord/howmanycol, HUMAN);
        }
    }
    for (int i = 458; i < 466; ++i){
        int coord =i;
        GenerateObject(coord/howmanycol, coord/howmanycol, HUMAN);
        GenerateObject(coord/howmanycol+1, coord/howmanycol, HUMAN);
    }
    GenerateObject(545/howmanycol, 545/howmanycol, HUMAN);
    GenerateObject(546/howmanycol, 546/howmanycol, HUMAN);
    GenerateObject(547/howmanycol, 547/howmanycol, HUMAN);
    for (int i = 615; i < 630; ++i){
        for (int j = 0; j < 6; ++j){
            int coord =i+j*howmanycol;
            GenerateObject(coord/howmanycol, coord/howmanycol, HUMAN);
        }
    }
    vector <int> chamber3;
    for (int i = 829; i < 841; ++i){
        for (int j = 0; j < 3; ++j){
            int coord =i+j*howmanycol;
            GenerateObject(coord/howmanycol, coord/howmanycol, HUMAN);
        }
    }
    vector <int> chamber4;
    for (int i = 1189; i < 1210; ++i){
        for (int j = 0; j < 7; ++j){
            int coord =i+j*howmanycol;
            GenerateObject(coord/howmanycol, coord/howmanycol, HUMAN);
        }
    }
    vector <int> chamber5;
    for (int i = 1539; i < 1578; ++i){
        for (int j = 0; j < 3; ++j){
            int coord =i+j*howmanycol;
            GenerateObject(coord/howmanycol, coord/howmanycol, HUMAN);
        }
    }
    for (int i = 1488; i < 1499; ++i){
        for (int j = 0; j < 3; ++j){
            int coord =i+j*howmanycol;
            GenerateObject(coord/howmanycol, coord/howmanycol, HUMAN);
        }
    }
}
