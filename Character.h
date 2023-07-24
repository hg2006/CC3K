#include "cc3klib.h"
#include "GameObject.h"
#include <vector>

class Character : public GameObject {
protected:
    MapItemType type;
    int currentHP;
    int maxHP;
    int atk;
    int def;
public:
    Character(int row, int col, Map *map, MapItemType type, int currentHP = 0, int maxHP = 0, int atk = 0, int def = 0);
    virtual ~Character();
    void setMap(Map *map);
    virtual void deadNotify();
    virtual void attackNotify();
    virtual void attacked(const int damage);
    void changeHP(const int HP);
    std::vector<CellType> detect() const;
    MapItemType GetType() override;
};
