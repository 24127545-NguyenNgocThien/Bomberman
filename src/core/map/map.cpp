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

Map::Map(int i) : id(i), fileName("map_") {
    loadMap(id);
}

Map::~Map() {}

const vector<vector<int>> &Map::getGrid() const {
    return grid;
}
