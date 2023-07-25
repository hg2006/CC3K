#include "Map.h"

int main(){
    Map* map = new Map{nullptr};
    BuffedPlayer *player = new Vampire{1,2,map};
    map->player = player;
    map->InitializeMap();
    map->RenderMap();
}