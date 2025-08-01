#ifndef UI_H
#define UI_H

#include "map/map.h"
#include "player/player.h"
#include "bomb/bomb.h"
#include "item/item.h"

class Ui {
private:
    float cellSize;
    int screenHeight, screenWidth;

    Ui();

public:
    Ui(const Ui& other) = delete;
    Ui& operator = (const Ui& other) = delete;
    static Ui& getInstance();

    void init(int scrWidth, int scrHeight, int cSize);
    void close();

    void drawMap(const Map& grid);
    void drawPlayer(const Player& player);
    void drawBomb(const Bomb& bomb);
    void drawExplosion(const Bomb& bomb);
    void drawItem(const Item& item);

    ~Ui();
};

#endif // UI_H
