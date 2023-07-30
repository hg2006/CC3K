#ifndef _BDDECORATOR_H_
#define _BDDECORATOR_H_

#include "Decorator.h"
#include "BuffedPlayer.h"

class BDDecorator : public Decorator {
public:
    BDDecorator(BuffedPlayer *component, int effect);
    ~BDDecorator();
    int getDef() const override;
};

#endif
