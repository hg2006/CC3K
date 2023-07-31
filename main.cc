#include "Map.h"
#include "Game.h"
using namespace std;

int main(){
    Game *game = new Game{"Goblin", GOBLIN};
    game->InitByFile("f1.txt");
    game->fRender();

}