#include "Goblin.h"

Goblin::Goblin(int row, int col, Map *map, MapItemType type, int currentHP, int maxHP, int atk, int def, int gold) :
    Player{row, col, map, type, currentHP, maxHP, atk, def, gold} {}

Goblin::~Goblin() {}

void Goblin::enemyIsKilled() {
    gold += 5;
}
