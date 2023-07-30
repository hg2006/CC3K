#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "BuffedPlayer.h"
#include "cc3klib.h"


class Player : public BuffedPlayer{
public:
    Player(int row, int col, Map *map, MapItemType type, int currentHP, int maxHP, int atk, int def, int gold);
    virtual ~Player() = 0;
    virtual void takePotion(const std::string direction) override;
    void attackNotify(const std::string direction) override;
    int getAtk() const;
    int getDef() const;
    virtual void enemyIsKilled() override{};
    virtual void endOfTurn() override{};
};

#endif
