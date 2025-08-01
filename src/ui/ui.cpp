#include "ui.h"
#include "raylib.h"

Ui::Ui() :screenHeight(0),screenWidth(0), cellSize(0)
{}

Ui &Ui::getInstance()
{
    static Ui instance;
    return instance;
}

void Ui::init(int scrWidth, int scrHeight, int cSize) {
    screenWidth = scrWidth;
    screenHeight = scrHeight;
    cellSize = cSize;
}

void Ui::drawMap(const Map& grid) {
    for(int y = 0; y < grid.getHeight(); ++y) {
        for(int x = 0; x < grid.getWidth(); ++x) {
            Rectangle cell = {x * cellSize, y * cellSize, cellSize, cellSize};

            switch(grid.getTileType(x, y)) {
            case 1:
            case 2:
            case 3:
            default:
                DrawRectangleRec(cell, DARKGRAY);
                break;
            }
        }
    }
}

void Ui::close() {

}

Ui::~Ui() {
    close();
}
