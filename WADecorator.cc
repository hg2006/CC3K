#include "WADecorator.h"
#include "Decorator.h"

WADecorator::WADecorator(BuffedPlayer *component, int effect) :
    Decorator{component, effect}

WADecorator::~WADecorator() {}

WADecorator::getAtk() {
    return component->getAtk() - effect;
}
