#include "Character.h"
#include "cc3klib.h"


class BuffedPlayer : Character {
protected:
    int gold;
public:
    BuffedPlayer(int row, int col, Map *map, std::string nameNotion = "Shade", int currentHP = 125, int maxHP = 125, int atk = 25, int def = 25,  int gold = 0);
    virtual ~BuffedPlayer();
    virtual void takePotion(const PotionType potion) const;
    virtual void attackNotify(const std::string direction);
    virtual int getAtk() const;
    virtual int getDef() const;
    virtual void moveDecision(std::string behaviour);
    virtual void enemyIsKilled();
    virtual void endOfTurn();
};
