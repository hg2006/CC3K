#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "BuffedPlayer.h"
#include "cc3klib.h"


class Player : public BuffedPlayer{
public:
    Player(int row, int col, Map *map, MapItemType type, int currentHP = 125, int maxHP = 125, int atk = 25, int def = 25, int gold = 0);
    virtual ~Player() = 0;
    virtual void takePotion(const PotionType potion) override;
    void attackNotify(const std::string direction) override;
    int getAtk() const;
    int getDef() const;
    virtual void enemyIsKilled() override{};
    virtual void endOfTurn() override{};
};

#endif
