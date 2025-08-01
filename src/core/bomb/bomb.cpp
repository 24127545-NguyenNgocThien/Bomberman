#include "bomb.h"

Bomb::Bomb(int X, int Y, int Scope)
    :x(X), y(Y), delayTime(1000), scope(1)
{}

void Bomb::IncreaseScope() {
    scope++;
    delayTime += 200;
}

void Bomb::update(double time) {
    delayTime -= time;
}

void Bomb::explore(Map& grid) {
    if(delayTime > 0) return;

    for(int i = 1; i <= scope; ++i) {
        grid.destroyBlock(x - i, y);
        grid.destroyBlock(x + i, y);
        grid.destroyBlock(x, y + i);
        grid.destroyBlock(x, y - 1);
    }
}
