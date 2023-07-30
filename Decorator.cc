#include "Decorator.h"
#include "BuffedPlayer.h"
#include <cmath>
#include <vector>

Decorator::Decorator(BuffedPlayer *component, int effect) :
    component{component}, effect{effect} {}

Decorator::~Decorator() {delete component;}

int Decorator::getAtk() const {
    return component->getAtk();
}

int Decorator::getDef() const {
    return component->getDef();
}

void Decorator::takePotion(const std::string direction) {
    std::vector<CellType> ct = this->detect();
    GameObject *obj = nullptr;
    if (direction == "nw") {
        if (ct[0] == POTION) {
            obj = map->GetObject(row - 1, col - 1);
        }
    } else if (direction == "no") {
        if (ct[1] == POTION) {
            obj = map->GetObject(row - 1, col);
        }
    } else if (direction == "ne") {
        if (ct[2] == POTION) {
            obj = map->GetObject(row - 1, col + 1);
        }
    } else if (direction == "we") {
        if (ct[3] == POTION) {
            obj = map->GetObject(row, col - 1);
        }
    } else if (direction == "ea") {
        if (ct[5] == POTION) {
            obj = map->GetObject(row, col + 1);
        }
    } else if (direction == "sw") {
        if (ct[6] == POTION) {
            obj = map->GetObject(row + 1, col - 1);
        }
    } else if (direction == "so") {
        if (ct[7] == POTION) {
            obj = map->GetObject(row + 1, col);
        }
    } else if (direction == "se") {
        if (ct[8] == POTION) {
            obj = map->GetObject(row + 1, col + 1);
        }
    }

    if (obj) {
        Potion *p = static_cast<Potion*>(obj);
        if (effect == 5) {
            const int changeHPNum = 10;
        } else {
            const int changeHPNum = 15;
        }
        if (p->IsReveal) {
            // print the name of this potion
        } else {
            // print unknow potion
        }
        MapItemType pt = p->Consume();
        if (pt == RH) {
            changeHP(changeHPNum);
        } else if (pt == PH) {
            changeHP(changeHPNum);
        } else if (pt == BA) {
            this = new BADecorator(this, effect);
        } else if (pt == BD) {
            this = new BDDecorator(this, effect);
        } else if (pt == WA) {
            this = new WADecorator(this, effect);
        } else if (pt == WD) {
            this = new WDDecorator(this, effect);
        }
    } else {
        // print there's no potion at this position
    }
}

void Decorator::attackNotify(const std::string direction) {
    std::vector<CellType> ct = this->detect();
    int atk = component->getAtk();
    if (direction == "nw") {
        if (ct[0] == ENEMY) {
            map->GetObject(row - 1, col - 1)->attacked(atk);
        }
    } else if (direction == "no") {
        if (ct[1] == ENEMY) {
            map->GetObject(row - 1, col)->attacked(atk);
        }
    } else if (direction == "ne") {
        if (ct[2] == ENEMY) {
            map->GetObject(row - 1, col + 1)->attacked(atk);
        }
    } else if (direction == "we") {
        if (ct[3] == ENEMY) {
            map->GetObject(row, col - 1)->attacked(atk);
        }
    } else if (direction == "ea") {
        if (ct[5] == ENEMY) {
            map->GetObject(row, col + 1)->attacked(atk);
        }
    } else if (direction == "sw") {
        if (ct[6] == ENEMY) {
            map->GetObject(row + 1, col - 1)->attacked(atk);
        }
    } else if (direction == "so") {
        if (ct[7] == ENEMY) {
            map->GetObject(row + 1, col)->attacked(atk);
        }
    } else if (direction == "se") {
        if (ct[8] == ENEMY) {
            map->GetObject(row + 1, col + 1)->attacked(atk);
        }
    }
}

void Decorator::attacked(const int damage) {
    int deductHP = -1 * std::ceil((1.0 * 100 / (100 + component->getDef())) * damage);
    changeHP(deductHP);
}

void Decorator::enemyIsKilled() {
    component->enemyIsKilled();
}

void Decorator::endOfTurn() {
    component->endOfTurn();
}
