#ifndef GAME
#define GAME

#include "cc3klib.h"
#include "BuffedPlayer.h"
#include "Map.h" // 

struct Game {
  private:
    int gameContinue = 1; // public
    int level;
    const int row = 25;
    const int col = 79;
    std::unique_ptr <BuffedPlayer> player;
    std::vector <std::unique_ptr <Map> > maps;
  public:
    Game(std::string nameNotion = "Shade", int currentHP = 125, int maxHP = 125, int Atk = 25, int Def = 25, int gold = 0);
    void UpdateGame ();
    void LevelUp ();
    void Render ();
    void Restart ();
    void GameOver ();
    void ScoreBoard ();
};

#endif
