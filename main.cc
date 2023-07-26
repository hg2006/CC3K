#include "Map.h"

int main(){
    Map* map = new Map{nullptr};
    BuffedPlayer *player = new Vampire{1,2,map};
    map->player = player;
    map->InitializeMap();
    map->RenderMap();
    for (int i = 0; i< 10; ++i) {
        player->moveDecision("ea");
        // player->attackNotify("ea");
        // player->attackNotify("we");
        // player->attackNotify("no");
        // player->attackNotify("so");
        // player->attackNotify("ne");
        // player->attackNotify("nw");
        // player->attackNotify("se");
        // player->attackNotify("sw");
    map->UpdateMap();
    map->RenderMap();
    }
    
}