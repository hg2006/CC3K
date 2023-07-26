#include "Game.h"

using namespace std;

Game::Game(string race, MapItemType type):
  level{1}, playerRace{race}, player {nullptr},
  maps {vector <unique_ptr <Map> > {}}
  {
    switch(type){
      case DROW:
        player = make_unique<Drow>(0,0,nullptr, type);
      case VAMPIRE:
        player = make_unique<Vampire>(0,0,nullptr, type);
      case TROLL:
        player = make_unique<Troll>(0,0,nullptr, type);
      case GOBLIN:
        player = make_unique<Goblin>(0,0,nullptr, type);
    }
    // shades missing

    for (int i = 0; i < 5; ++i ){
      maps.emplace_back(make_unique<Map>(this->player.get()));
    }
    Map &p = *(maps.front());
    // mutate player map
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
    // mutate player map
    level += 1;
  }
}

void Game::Render(){
  Map &p = *(maps.at(level-1));
  p.RenderMap();
  int gold = player->getGold();
  cout << "Race: " << playerRace << " Gold: " << gold << endl;
  //cout << "HP: " << player->getHP() << endl;
  cout << "Atk: " << player->getAtk() << endl;
  cout << "Def: " << player->getDef() << endl;
  cout << "Action: " << endl; // TODO
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
  //int score = player->getScore();
  cout << "--------------------------------" << endl;
  cout << "    Congratuations! You Win!    " << endl;
  cout << "    Your score is " << score << "." << endl;
  cout << "--------------------------------" << endl;
  cout << "        Restart or Quit?        " << endl;
  gameContinue = 0;
}

