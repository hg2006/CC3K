#include "WD.h"
#include "cc3klib.h"

WD::WD() {}

WD::~WD() {}

bool WD::IsRevealed() {
    return WDReveal;
}

MapItemType WD::Consume() {
    WDReveal = true;
    detach();
    return WD;
}

