#include "Map.h"
#include "Game.h"

int main(){
    Game *game = new Game{"Goblin", GOBLIN};
    game->Render();
    game->LevelUp();
    game->Render();
    game->LevelUp();
    game->Render();
    game->LevelUp();
    game->Render();
    game->LevelUp();
    game->Render();
    game->LevelUp();
}