#include "Map.h"
#include "Game.h"
using namespace std;

int main(){
    Game *game = new Game{"Goblin", GOBLIN};
    cout << game->GameStatus() << endl;
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
     game->GameOver();
    cout << game->GameStatus() << endl;
}