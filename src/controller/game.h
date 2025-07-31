#ifndef GAME_H
#define GAME_H

#include "map/map.h"

class Game {
private:
    Map grid;

public:
    void Render();
};

#endif // GAME_H
