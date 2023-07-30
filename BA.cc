#include "BA.h"
#include "cc3klib.h"

BA::BA() {}

BA::~BA() {}

bool BA::IsRevealed() {
    return BAReveal;
}

MapItemType BA::Consume() {
    BAReveal = true;
    detach();
    return BA;
}

