#include "BADecorator.h"
#include "Decorator.h"

BADecorator::BADecorator(BuffedPlayer *component, int effect) :
    Decorator{component, effect} {}

BADecorator::~BADecorator() {}

int BADecorator::getAtk() const {
    return component->getAtk() + effect;
}
