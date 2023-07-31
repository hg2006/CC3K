#ifndef _DECORATOR_H_
#define _DECORATOR_H_

#include "BuffedPlayer.h"

class Decorator : public BuffedPlayer {
protected:
    BuffedPlayer *component;
    int effect;
public:
    Decorator(BuffedPlayer *bp, int effect);
    virtual ~Decorator();
    virtual int getAtk() const override;
    virtual int getDef() const override;
    void takePotion(const std::string direction) override;
    void attackNotify(const std::string direction) override;
    void attacked(const int damage) override;
    void enemyIsKilled() override;
    void endOfTurn() override;
};

#endif
