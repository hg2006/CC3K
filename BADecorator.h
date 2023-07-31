#ifndef _BADECORATOR_H_
#define _BADECORATOR_H_

#include "Decorator.h"
#include "BuffedPlayer.h"

class BADecorator : public Decorator {
public:
    BADecorator(BuffedPlayer *component, int effect);
    ~BADecorator();
    int getAtk() const override;
};

#endif
