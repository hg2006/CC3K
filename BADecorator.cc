#include "BADecorator.h"
#include "Decorator.h"

BADecorator::BADecorator(BuffedPlayer *component, int effect) :
    Decorator{component, effect}

BADecorator::~BADecorator() {}

BADecorator::getAtk() {
    return component->getAtk() + effect;
}
