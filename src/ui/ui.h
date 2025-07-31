#ifndef UI_H
#define UI_H

#include "map/map.h"

class Ui {
private:
    int cellSize = 30;

    Ui() {};

public:
    Ui(const Ui& other) = delete;
    Ui& operator = (const Ui& other) = delete;
    static Ui& getInstance();

    void drawMap(const vector<vector<int>>& grid);
};

#endif // UI_H
