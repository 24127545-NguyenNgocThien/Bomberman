#ifndef PLAYER_H
#define PLAYER_H

#include "map/map.h"

class Item;
class Bomb;

class Player
{
private:
    int x, y;
    double speed;
    int maxBombs;
    int bombScope;
    double health;
    bool isAlive;

public:
    char direction;

    Player(int X, int Y);

    Bomb* placeBomb(Map& grid);
    void move(const Map& grid, char direction);
    void takeDamage(double damage);
    void colectItem(Item& item);
    void update(double time, const Map& grid);

    void increaseSpeed();
    void increaseMaxBoms();
    void increaseBombScope();

};

#endif // PLAYER_H
