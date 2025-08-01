#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include <utility>
using std::string, std::vector;

class Map {
private:
    vector<vector<int>> grid;
    int id;
    int width, height;
    string fileName;
    std::pair<int, int> spawnPoints[4];

    void loadMap(int id);

public:
    Map(int w, int h);
    ~Map();

    void chooseMap(int id);

    // const vector<vector<int>>& getGrid() const;
    bool isWalkable(int x, int y) const;
    void destroyBlock(int x, int y);
    int getTileType(int x, int y) const;
    void setTileType(int x, int y, int type);
    std::pair<int, int> getSpawnPoint(int id);
    int getWidth() const;
    int getHeight() const;
};

#endif // MAP_H
