#ifndef _TEST_H_
#define _TEST_H_
#include "cc3klib.h"

class GameObject{
public:
    GameObject* GetObject(){return this;}
    virtual MapItemType GetType() = 0;
    CellType GetCellType(){return OBSTACLE;}
    void update(){}
};

class BuffedPlayer{
public:
    BuffedPlayer(): col{0}, row{0} {}
    int col;
    int row;
    int Getx(){return 0;}
    int Gety(){return 0;}
};

class Human: public GameObject{
    public:
    int x;
    int y;
    Human(int x, int y): x{x}, y{y} {}
    MapItemType GetType(){return HUMAN;}
};

class Dwarf: public GameObject{
    public:
    int x;
    int y;
    Dwarf(int x, int y): x{x}, y{y} {}
    MapItemType GetType(){return DWARF;}
};

class Elf: public GameObject{
    public:
    int x;
    int y;
    Elf(int x, int y): x{x}, y{y} {}
    MapItemType GetType(){return ELF;}
};

class Orc: public GameObject{
    public:
    int x;
    int y;
    Orc(int x, int y): x{x}, y{y} {}
    MapItemType GetType(){return ORCS;}
};

class Merchant: public GameObject{
    public:
    int x;
    int y;
    Merchant(int x, int y): x{x}, y{y} {}
    MapItemType GetType(){return MERCHANT;}
};

class Halfing: public GameObject{
    public:
    int x;
    int y;
    Halfing(int x, int y): x{x}, y{y} {}
    MapItemType GetType(){return HALFLING;}
};

class SmallGold: public GameObject{
    public:
    int x;
    int y;
    SmallGold(int x, int y): x{x}, y{y} {}
    MapItemType GetType(){return SMALLGOLD;}
};

class NormalGold: public GameObject{
    public:
    int x;
    int y;
    NormalGold(int x, int y): x{x}, y{y} {}
    MapItemType GetType(){return NORMALGOLD;}
}; 

class MerchantHoard: public GameObject{
    public:
    int x;
    int y;
    MerchantHoard(int x, int y): x{x}, y{y} {}
    MapItemType GetType(){return MERCHANTHOARD;}
};

class DragonHoard: public GameObject{
    public:
    int x;
    int y;
    DragonHoard(int x, int y): x{x}, y{y} {}
    MapItemType GetType(){return DRAGONHOARD;}
};



#endif
