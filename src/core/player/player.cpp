#include "player.h"
#include "bomb/bomb.h"
#include "item/item.h"
#include <iostream>

Player::Player(int X, int Y)
    :x(X), y(Y), speed(5), maxBombs(1)
{}

Bomb* Player::placeBomb(Map& grid) {
    Bomb* b = new Bomb(x, y, bombScope);
    return b;
}

void Player::move(const Map& grid, char direction) {
    switch(direction) {
    case 'W':
        if(grid.isWalkable(y - 1, x))
            y -= speed;
        break;
    case 'A':
        if(grid.isWalkable(y, x - 1))
            x -= speed;
        break;
    case 'S':
        if(grid.isWalkable(y + 1, x))
            y += speed;
        break;
    case 'D':
        if(grid.isWalkable(y, x + 1))
            x += speed;
        break;
    default:
        std::cerr << "Invalid argument!\n";
        break;
    }
}

void Player::takeDamage(double damage) {
    health -= damage;
    if(health <= 0) {
        isAlive = false;
    }
}

void Player::colectItem(Item& item) {
    item.applyEffect(*this);
    item.active();
}

//============================================================================================
void Player::update(double time, const Map& grid) {

}
//============================================================================================

void Player::increaseSpeed() {
    speed += 5;
}

void Player::increaseMaxBoms() {
    maxBombs += 5;
}

void Player::increaseBombScope() {
    bombScope += 5;
}
