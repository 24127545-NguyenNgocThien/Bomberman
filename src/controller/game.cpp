#include "game.h"
#include "ui.h"
#include <random>

Game::Game()
    :grid(nullptr), players({}), bombs({}), items({}), gameState(0)
{}

Game::~Game() {
    if(grid) delete grid;
    for(auto player : players) {
        if(player) delete player;
    }
    for(auto item : items) {
        if(item) delete item;
    }
    for(auto bomb : bombs) {
        if(bomb) delete bomb;
    }
}

// Hàm sinh số ngẫu nhiên trong khoảng [min, max]
int randomInt(int min, int max) {
    static std::random_device rd;  // Khởi tạo seed ngẫu nhiên
    static std::mt19937 gen(rd()); // Engine ngẫu nhiên (Mersenne Twister)
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

void Game::init() {
    grid->chooseMap(randomInt(0, 2));

    std::pair<int, int> pos;
    for(int i = 0; i < players.size(); ++i) {
        pos = grid->getSpawnPoint(i);
        Player* player = new Player(pos.first, pos.second);
        players.push_back(player);
    }

    for(int i = 0; i < 10; i++) {
        int x, y, type;
        x = randomInt(1, 39);
        y = randomInt(1, 29);
        type = randomInt(0, 2);
        Item* item = new Item(x, y, type);
        items.push_back(item);
    }

    gameState = 1;
}

void Game::render()
{
    Ui::getInstance().drawMap(*grid);
}
