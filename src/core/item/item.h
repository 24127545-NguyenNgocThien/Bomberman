#ifndef ITEM_H
#define ITEM_H

#include "player/player.h"

class Item
{
private:
    int x, y;
    int type;
    bool isActive;

public:
    Item(int X, int Y, int type);

    void applyEffect(Player& p);
    void active();
};

#endif // ITEM_H
