#include "BDDecorator.h"
#include "Decorator.h"

BDDecorator::BDDecorator(BuffedPlayer *component, int effect) :
    Decorator{component, effect}

BDDecorator::~BDDecorator() {}

BDDecorator::getDef() {
    return component->getDef() + effect;
}

