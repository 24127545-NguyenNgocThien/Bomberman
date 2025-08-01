#include "map.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>
using std::ifstream, std::cerr, std::istringstream, std::cin, std::getline;


std::string GetResourcePath(const std::string& fileName, int id) {
    // Kết hợp đường dẫn an toàn
    std::filesystem::path fullPath = std::string(RESOURCES_PATH) + "/" + fileName
        +std::to_string(id) + ".csv";
    return fullPath.string();  // Chuyển về string phù hợp với hệ điều hành
}

void Map::loadMap(int id) {
    string fullPath = GetResourcePath(fileName, id);
    ifstream file(fullPath);
    if(!file.is_open()) {
        cerr << "Ko the mo file!\n";
        return;
    }

    string line;
    while(getline(file, line)) {
        vector<int> row;
        istringstream iss(line);
        int tile;
        while(iss >> tile) {
            row.push_back(tile);
        }

        grid.push_back(row);
    }
    file.close();
    return;
}

Map::Map(int w, int h)
    :width(w), height(h), id(0), fileName("map_")
{
    spawnPoints[0] = {1, 1};
    spawnPoints[1] = {38, 28};
    spawnPoints[2] = {38, 1};
    spawnPoints[3] = {1, 28};
}

void Map::chooseMap(int id) {
    this->id = id;
    loadMap(this->id);
}

Map::~Map() {}

// const vector<vector<int>> &Map::getGrid() const {
//     return grid;
// }

bool Map::isWalkable(int x, int y) const {
    return (grid[x][y] == 0);
}

void Map::destroyBlock(int x, int y) {
    int cellType = grid[x][y];
    if(cellType == 1 || cellType == 2)
        grid[x][y]--;
}

int Map::getTileType(int x, int y) const {
    return grid[x][y];
}

void Map::setTileType(int x, int y, int type) {
    grid[x][y] = type;
}

std::pair<int, int> Map::getSpawnPoint(int id) {
    std::pair<int, int> spawnPoint;
    spawnPoint = spawnPoints[id];
    return spawnPoint;
}

int Map::getWidth() const {
    return width;
}

int Map::getHeight() const {
    return height;
}
