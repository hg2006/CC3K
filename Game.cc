#include "Game.h"

using namespace std;

Game::Game(string race, MapItemType type):
  level{1}, playerRace{race}, player {nullptr},
  maps {vector <unique_ptr <Map> > {}}
  {
    switch(type){
      case DROW:
        player = make_unique<Drow>(0,0,nullptr, type);
        break;
      case VAMPIRE:
        player = make_unique<Vampire>(0,0,nullptr, type);
        break;
      case TROLL:
        player = make_unique<Troll>(0,0,nullptr, type);
        break;
      case GOBLIN:
        player = make_unique<Goblin>(0,0,nullptr, type);
        break;
    }
    // shades missing

    for (int i = 0; i < 5; ++i ){
      maps.emplace_back(make_unique<Map>(this->player.get()));
    }
  }

BuffedPlayer& Game::GetPlayer(){
  return *player;
}

Map& Game::GetMap(){
  return *(maps.at(level-1));
}

void Game::InitializeGame(){
  for (auto &p : maps){
    (*p).InitializeMap();
  }
  Map &p = *(maps.front());
  player->setMap(&p);
  player->SetRow(p.playerrow);
  player->SetCol(p.playercol);
}

void Game::InitByFile(string filename){
  int colsize = 79;
  ifstream f {filename};
  char ch;
  for (int j = 0; j < 5; ++j){
    Map &p = *(maps.at(j));
    for (int i = 0; i < 1975; ++i){
      ch = f.get();
      if (ch == '\n'){
        ch = f.get();
      }
      switch (ch) {
        case 'H':
          p.GenerateObject(i/colsize, i%colsize, HUMAN);
          break;
        case 'W':
          p.GenerateObject(i/colsize, i%colsize, DWARF);
          break;
        case 'E':
          p.GenerateObject(i/colsize, i%colsize, ELF);
          break;
        case 'O':
          p.GenerateObject(i/colsize, i%colsize, ORCS);
          break;
        case 'M':
          p.GenerateObject(i/colsize, i%colsize, MERCHANT);
          break;
        case 'D':
          p.GenerateObject(i/colsize, i%colsize, DRAGON);
          break;
        case 'L':
          p.GenerateObject(i/colsize, i%colsize, HALFLING);
          break;
        case '0':
          p.GenerateObject(i/colsize, i%colsize, RH);
          break;
        case '1':
          p.GenerateObject(i/colsize, i%colsize, BA);
          break;
        case '2':
          p.GenerateObject(i/colsize, i%colsize, BD);
          break;
        case '3':
          p.GenerateObject(i/colsize, i%colsize, PH);
          break;
        case '4':
          p.GenerateObject(i/colsize, i%colsize, WA);
          break;
        case '5':
          p.GenerateObject(i/colsize, i%colsize, WD);
          break;
        case '6':
          p.GenerateObject(i/colsize, i%colsize, NORMALGOLD);
          break;
        case '7':
          p.GenerateObject(i/colsize, i%colsize, SMALLGOLD);
          break;
        case '8':
          p.GenerateObject(i/colsize, i%colsize, MERCHANTHOARD);
          break;
        case '9':
          p.GenerateObject(i/colsize, i%colsize, DRAGONHOARD);
          break;
        case '@':
          p.playerrow = i/colsize;
          p.playercol = i%colsize;
          break;
         case '\\':
           p.GenerateObject(i/colsize, i%colsize, ASTAIR);
           break;
      }
    }
  }
  Map &p = *(maps.front());
  player->setMap(&p);
  player->SetRow(p.playerrow);
  player->SetCol(p.playercol);
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
    player->setMap(&p);
    player->SetRow(p.playerrow);
    player->SetCol(p.playercol);
    level += 1;
  }
}

int Game::GameStatus(){
  return gameContinue;
}

void Game::Render(){
  Map &p = *(maps.at(level-1));
  p.RenderMap();
  int gold = player->getGold();
  cout << "Race: " << playerRace << " Gold: " << gold << endl;
  cout << "HP: " << player->getHP() << endl;
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
  int score = player->getScore();
  cout << "--------------------------------" << endl;
  cout << "    Congratuations! You Win!    " << endl;
  cout << "    Your score is " << score << "." << endl;
  cout << "--------------------------------" << endl;
  cout << "        Restart or Quit?        " << endl;
  gameContinue = 0;
}

