#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
using std::string, std::vector;

class Map {
private:
    vector<vector<int>> grid;
    int id;
    string fileName;

    void loadMap(int id);

public:
    Map(int i = 0);
    ~Map();

    const vector<vector<int>>& getGrid() const;
};

#endif // MAP_H
