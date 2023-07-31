#include "Human.h"
#include "Map.h"

Human::Human(int row, int col, Map *map, MapItemType type, int currentHP, int maxHP, int atk, int def) :
    Enemy{row, col, map, type, currentHP, maxHP, atk, def} {}
Human::~Human() {}

void Human::deadNotify() {
    map->GetPlayer()->enemyIsKilled();
    detach();
}
