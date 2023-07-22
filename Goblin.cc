#include "Goblin.h"

Goblin::Goblin(int row, int col, Map *map, std::string nameNotion, int currentHP, int maxHP, int atk, int def, int gold) :
    Player{row, col, map, nameNotion, currentHP, maxHP, atk, def, gold} {}

Goblin::~Goblin() {}

void Goblin::enemyIsKilled() {
    gold += 5;
}
