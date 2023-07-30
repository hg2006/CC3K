#include "RH.h"
#include "cc3klib.h"

RH::RH() {}

RH::~RH() {}

bool RH::IsRevealed() {
    return RHReveal;
}

MapItemType RH::Consume() {
    RHReveal = true;
    detach();
    return RH;
}

