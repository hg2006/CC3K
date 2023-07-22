#include "Character.h"
#include "cc3klib.h"

Character::Character(int row, int col, Map *map, std::string nameNotion, int currentHP, int maxHP, int atk, int def) : 
    row{row}, col{col}, map{map}, nameNotion{nameNotion}, currentHP{currentHP}, maxHP{maxHP}, atk{atk}, def{def}
{}

Character::~Character(delete map);

std::string Character::getName() {
    return nameNotion;
}

void Character::deadNotify() {
    map->detach(row, col); 
}

void Character::attackNotify() {} // this behaviour is purely virtual

void Character::attacked(const int damage) {
    int deductHP = -1 * ceil((1.0 * 100 / (100 + def)) * damage);
    changeHP(deductHP);
}

void Character::changeHP(const int HP) {
    int tmpHP = currentHP + HP;
    if (tmpHP > maxHP) {
        currentHP = maxHP;
    } else if (tmpHP < 0) {
        currentHP = 0;
        deadNotify();
    } else {
        currentHP = tmpHP;
    }
}

CellType* Character::detect() const {
    return map->GetViews(row, col);
}
