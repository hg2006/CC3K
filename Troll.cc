#include "Troll.h"
#include "cc3klib.h"

Troll::Troll(int row, int col, Map *map, std::string nameNotion, int currentHP, int maxHP, int atk, int def, int gold) :
    Player{row, col, map, nameNotion, currentHP, maxHP, atk, def, gold} {}

Troll::~Troll() {}

void Troll::endOfTurn() {
    changeHP(5);
}