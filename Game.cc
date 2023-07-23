#include "Game.h"

using namespace std;

Game::Game(string nameNotion, int currentHP, int maxHP, int Atk, int Def, int gold):
  level{1}, player { make_unique <BuffedPlayer> (nameNotion, currentHP, maxHP, Atk, Def, gold)},
  maps {vector < <unique_ptr <Map> > temp}
  {
    
  }
