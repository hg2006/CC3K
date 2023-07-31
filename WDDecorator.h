#ifndef _WDDECORATOR_H_
#define _WDDECORATOR_H_

#include "Decorator.h"
#include "BuffedPlayer.h"

class WDDecorator : public Decorator {
public:
    WDDecorator(BuffedPlayer *component, int effect);
    ~WDDecorator();
    int getDef() const override;
};

#endif
