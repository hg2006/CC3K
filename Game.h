#ifndef GAME
#define GAME

#include "cc3klib.h"
#include "BuffedPlayer.h"
#include "Map.h" // 

class Game {
    int gameContinue = 1; // public
    int level;
    std::string playerRace;
    const int row = 25;
    const int col = 79;
    std::unique_ptr <BuffedPlayer> player;
    std::vector <std::unique_ptr <Map> > maps;
  public:
    Game(std::string race, MapItemType type);
    BuffedPlayer& GetPlayer();
    Map& GetMap();
    void InitializeGame();
    void InitByFile(std::string filename);
    int GameStatus ();
    void UpdateGame ();
    void LevelUp ();
    void Render ();
    void GameOver ();
    void ScoreBoard ();
};

#endif
