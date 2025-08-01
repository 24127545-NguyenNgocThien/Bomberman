#ifndef BOMB_H
#define BOMB_H

// #include "player/player.h"
#include "map/map.h"

class Bomb
{
private:
    int x, y;
    double delayTime;
    int scope;
    bool isExplore;
    // Player owner;

public:
    Bomb(int X, int Y, int scope);

    void IncreaseScope(); // set delayTime kem theo
    void update(double time);
    void explore(Map& grid);
};

#endif // BOMB_H
