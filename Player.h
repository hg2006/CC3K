#include "BuffedPlayer.h"
#include "cc3klib.h"

class Player : public BuffedPlayer{
protected:
    int gold;
public:
    Player(int row, int col, string nameNotion = "Shade", int currentHP = 125, int maxHP = 125, int atk = 25, int def = 25, int gold = 0);
    virtual ~Player();
    void deadNotify() override;
    virtual void takePotion(const PotionType potion) const override;
    virtual void attackNotify(const string direction) override;
    void attacked(const int damage) override;
    int getAtk() const;
    int getDef() const;
    void moveDecision(string behaviour) override;
    virtual void enemyIsKilled() override;
    virtual void endOfTurn() override;
};
