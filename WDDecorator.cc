#include "WDDecorator.h"
#include "Decorator.h"

WDDecorator::WDDecorator(BuffedPlayer *component, int effect) :
    Decorator{component, effect}

WDDecorator::~WDDecorator() {}

WDDecorator::getDef() {
    if (component->getDef() > effect) {
        return component->getDef() - effect;
    }
    return 0;
}

