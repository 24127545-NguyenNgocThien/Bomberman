#ifndef GAME_H
#define GAME_H

#include "map/map.h"
#include "player/player.h"
#include "bomb/bomb.h"
#include "item/item.h"

class Game {
private:
    Map* grid;
    vector<Player*> players;
    vector<Bomb*> bombs;
    vector<Item*> items;
    int gameState;

public:
    Game();
    ~Game();

    void init();
    void update(double time);
    void render();
    void run();
    void handleInput();
};

#endif // GAME_H
