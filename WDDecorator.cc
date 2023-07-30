#include "WDDecorator.h"
#include "Decorator.h"

WDDecorator::WDDecorator(BuffedPlayer *component, int effect) :
    Decorator{component, effect}

WDDecorator::~WDDecorator() {}

WDDecorator::getDef() {
    return component->getDef() - effect;
}

