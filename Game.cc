#include "Game.h"

using namespace std;

Game::Game(string nameNotion, int currentHP, int maxHP, int Atk, int Def, int gold):
  level{1}, player { make_unique <BuffedPlayer> (nameNotion, currentHP, maxHP, Atk, Def, gold)},
  maps {vector <unique_ptr <Map> > {}}
  {
    for (int i = 0; i < 5; ++i ){
      maps.emplace_back(make_unique<Map>(this->player.get()));
    }
    Map &p = *(maps.front());
    p.InitializeMap();
  }


void Game::UpdateGame(){
  Map &p = *(maps.at(level-1));
  p.UpdateMap();
}

void Game::LevelUp(){
  if (level == 5) {
    ScoreBoard ();
  }
  else {
    Map &p = *(maps.at(level));
    p.InitializeMap();
    level += 1;
  }
}

void Game::Render(){
  Map &p = *(maps.at(level-1));
  p.RenderMap();
}

void Game::GameOver(){
  cout << "--------------------------------" << endl;
  cout << "            You lose.           " << endl;
  cout << "--------------------------------" << endl;
  cout << "        Restart or Quit?        " << endl;
  gameContinue = 0;
}

void Game::ScoreBoard(){
  int score = 10;
  //int score = player->gold; // need access to gold
  //if (player->nameNotion == "Shade") score = score + score/2; // virtual gold accessor may be better
  cout << "--------------------------------" << endl;
  cout << "    Congratuations! You Win!    " << endl;
  cout << "    Your score is" << score << endl;
  cout << "--------------------------------" << endl;
  cout << "        Restart or Quit?        " << endl;
  gameContinue = 0;
}

