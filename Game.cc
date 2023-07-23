#include "Game.h"

using namespace std;

Game::Game(string nameNotion, int currentHP, int maxHP, int Atk, int Def, int gold):
  level{1}, player { make_unique <BuffedPlayer> (nameNotion, currentHP, maxHP, Atk, Def, gold)},
  maps {vector <unique_ptr <Map> > {}}
  {
    for (int i = 0; i < 5; ++i ){
      maps.emplace_back(make_unique<Map>(this->player.get()));
    }
    unique_ptr <Map> &p = maps.front();
    p->InitializeMap();
  }
