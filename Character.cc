#include "Character.h"
#include "Map.h"

Character::Character(int row, int col, Map *map, MapItemType type, int currentHP, int maxHP, int atk, int def) : 
    GameObject{row, col, map}, type{type}, currentHP{currentHP}, maxHP{maxHP}, atk{atk}, def{def}
{}

Character::~Character() {}

void Character::deadNotify() {
    detach();
}

void Character::attacked(const int damage) {    
    int deductHP = -1 * std::ceil((1.0 * 100 / (100 + def)) * damage);
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

std::vector<CellType> Character::detect() const {
    return map->GetViews(row, col);
}

MapItemType Character::GetType() {
    return type;
}

int Character::getHP() {
    return currentHP;
}
