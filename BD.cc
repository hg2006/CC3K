#include "BD.h"
#include "cc3klib.h"

BD::BD() {}

BD::~BD() {}

bool BD::IsRevealed() {
    return BDReveal;
}

MapItemType BD::Consume() {
    BDReveal = true;
    detach();
    return BD;
}

