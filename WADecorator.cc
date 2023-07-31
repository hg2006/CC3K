#include "WADecorator.h"
#include "Decorator.h"

WADecorator::WADecorator(BuffedPlayer *component, int effect) :
    Decorator{component, effect}

WADecorator::~WADecorator() {}

WADecorator::getAtk() {
    if (component->getAtk() > effect) {
        return component->getAtk() - effect;
    }
    return 0;
}
