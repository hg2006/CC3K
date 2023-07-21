#ifndef GAME
#define GAME

#include "cc3klib.h"
#include "BuffedPlayer.h"

struct Game {
  private:
    int level;
    unique_ptr <BuffedPlayer> player;
    vector <unique_ptr <Map>> maps;
  public:
    Game();
    void UpdateGame ();
    void LevelUp ();
    string Render ();
    void Restart ();
    void GameOver ();
    void ScoreBoard ();
}

#endif
