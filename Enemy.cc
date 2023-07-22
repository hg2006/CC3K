#include "Enemy.h"

Enemy::Enemy(int row, int col, Map *map, std::string nameNotion = "", int currentHP = 0, int maxHP = 0, int atk = 0, int def = 0);
Enemy::~Enemy();
void Enemy::deadNotify() override;
void Enemy::attackNotify() override;
void Enemy::attacked(const int damage) override;
void Enemy::moveDecision();
