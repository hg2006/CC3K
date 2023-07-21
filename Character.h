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
    Character(int row, int col, string nameNotion = "", int currentHP = 0, int maxHP = 0, int atk = 0, int def = 0);
    virtual ~Character();
    // 下面这三个暂时不确定是不是const
    void setMap(Map *map);
    virtual void deadNotify();
    virtual void attackNotify();
    virtual void attacked(const int damage);
    void changeHP(const int HP);
    CellType* detect() const;
};
