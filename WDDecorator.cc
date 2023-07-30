#include "WDDecorator.h"
#include "Decorator.h"

WDDecorator::WDDecorator(BuffedPlayer *component, int effect) :
    Decorator{component, effect} {}

WDDecorator::~WDDecorator() {}

int WDDecorator::getDef() const {
    return component->getDef() - effect;
}

