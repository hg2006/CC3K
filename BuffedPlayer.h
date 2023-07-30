#ifndef _BUFFEDPLAYER_H_
#define _BUFFEDPLAYER_H_

#include "Character.h"
#include "cc3klib.h"
// #include "Map.h" Might not be necessary
// #include "Character.h"

class BuffedPlayer:public Character{
protected:
    int gold;
public:
    BuffedPlayer(int row, int col, Map *map, MapItemType type = SHADE, int currentHP = 125, int maxHP = 125, int atk = 25, int def = 25,  int gold = 0);
    BuffedPlayer();
    virtual ~BuffedPlayer() = 0;
    virtual void takePotion(const std::string direction);
    virtual void attackNotify(const std::string direction);
    virtual int getAtk() const;
    virtual int getDef() const;
    virtual void moveDecision(std::string behaviour);
    virtual void enemyIsKilled();
    virtual void endOfTurn();
    void changeGold(int goldNum);
    int getGold();
    virtual int getScore();
};

#endif
