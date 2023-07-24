#include "Drow.h"
#include "cc3klib.h"

Drow::Drow(int row, int col, Map *map, MapItemType type,  int currentHP, int maxHP, int atk, int def, int gold) :
    Player{row, col, map, type, currentHP, maxHP, atk, def, gold} {}

Drow::~Drow() {}

void Drow::takePotion(const PotionType potion) {
    
}
