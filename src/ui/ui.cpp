#include "ui.h"
#include "raylib.h"

Ui &Ui::getInstance()
{
    static Ui instance;
    return instance;
}

void Ui::drawMap(const vector<vector<int>> &grid)
{
    for(int i = 0; i < grid.size(); ++i) {
        vector<int> row = grid[i];

        for(int j = 0; j < row.size(); ++j) {
            int cell = grid[i][j];

            //qui uoc 0: khoang trang; 1: ko the pha; 2: pha 1 lan; 3: pha 2 lan;
            if(cell == 1) DrawRectangle(i * cellSize, j * cellSize, cellSize, cellSize, GRAY);
            else if(cell == 2) DrawRectangle(i * cellSize, j * cellSize, cellSize, cellSize, BROWN);
            else if(cell == 3) DrawRectangle(i * cellSize, j * cellSize, cellSize, cellSize, DARKBROWN);
            else DrawRectangle(i * cellSize, j * cellSize, cellSize, cellSize, BLANK);
        }
    }
}
