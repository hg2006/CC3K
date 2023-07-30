#include "BDDecorator.h"
#include "Decorator.h"

BDDecorator::BDDecorator(BuffedPlayer *component, int effect) :
    Decorator{component, effect} {}

BDDecorator::~BDDecorator() {}

int BDDecorator::getDef() const {
    return component->getDef() + effect;
}

