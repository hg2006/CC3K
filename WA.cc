#include "WA.h"
#include "cc3klib.h"

WA::WA() {}

WA::~WA() {}

bool WA::IsRevealed() {
    return WAReveal;
}

MapItemType WA::Consume() {
    WAReveal = true;
    detach();
    return WA;
}

