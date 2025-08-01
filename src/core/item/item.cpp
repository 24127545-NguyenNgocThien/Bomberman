#include "item.h"

Item::Item(int X, int Y, int Type)
    :x(X), y(Y), type(Type), isActive(false)
{}

void Item::applyEffect(Player& p) {
    switch(type) {
    case 1:
        p.increaseSpeed();
        break;
    case 2:
        p.increaseBombScope();
        break;
    case 3:
        p.increaseMaxBoms();
        break;
    default:
        return;
    }
}

void Item::active() {
    isActive = true;
}
