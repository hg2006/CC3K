#include "cc3klib.h"

class Character {
protected:
    Map *map;
    string nameNotion;
    int currentHP;
    int maxHP;
    int atk;
    int def;
public:
    Character(string nameNotion = "", int currentHP = 0, int maxHP = 0, int atk = 0, int def = 0);
    virtual ~Character();
    // 下面这三个暂时不确定是不是const
    virtual void deadNotify();
    virtual void attackNotify(const string direction);
    virtual void attacked(const int damage);
    void changeHP(const int HP);
    CellType* detect() const;
};
