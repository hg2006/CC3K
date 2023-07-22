#include "Drow.h"
#include "cc3klib.h"

Drow::Drow(int row, int col, Map *map, std::string nameNotion, int currentHP, int maxHP, int atk, int def, int gold) {
    Player{row, col, map, nameNotion, currentHP, maxHP, atk, def, gold} {}
}

Dorw::~Drow() {}

void Drow::takePotion(const PotionType potion) const {
    
}
