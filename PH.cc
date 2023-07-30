
#include "PH.h"
#include "cc3klib.h"

PH::PH() {}

PH::~PH() {}

bool PH::IsRevealed() {
    return PHReveal;
}

MapItemType PH::Consume() {
    PHReveal = true;
    detach();
    return PH;
}

