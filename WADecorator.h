#ifndef _WADECORATOR_H_
#define _WADECORATOR_H_

#include "Decorator.h"
#include "BuffedPlayer.h"

class WADecorator : public Decorator {
public:
    WADecorator(BuffedPlayer *component, int effect);
    ~WADecorator();
    int getAtk() const override;
};

#endif
