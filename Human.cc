#include "Human.h"


Human::Human(int row, int col, Map *map, std::string nameNotion, int currentHP, int maxHP, int atk, int def) :
    Enemy{row, col, map, nameNotion, currentHP, maxHP, atk, def} {}
Human::~Human() {}

