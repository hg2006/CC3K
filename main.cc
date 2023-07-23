#include "Map.h"

int main(){
    BuffedPlayer *player = new BuffedPlayer{};
    Map* map = new Map{player};
    map->InitializeMap();
    map->RenderMap();
}
