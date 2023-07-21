#include "Character.h"
#include "cc3klib.h"

class BuffedPlayer : Character {
public:
    virtual ~BuffedPlayer();
    virtual void takePotion(const PotionType potion) const;
    virtual int getAtk() const;
    virtual int getDef() const;
    virtual void moveDecision(string behaviour);
    virtual void enemyIsKilled();
    virtual void endOfTurn();
};
