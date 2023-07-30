#include "WADecorator.h"
#include "Decorator.h"

WADecorator::WADecorator(BuffedPlayer *component, int effect) :
    Decorator{component, effect} {}

WADecorator::~WADecorator() {}

int WADecorator::getAtk() const {
    return component->getAtk() - effect;
}
