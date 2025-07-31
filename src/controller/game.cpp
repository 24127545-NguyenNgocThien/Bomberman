#include "game.h"
#include "ui.h"

void Game::Render()
{
    Ui::getInstance().drawMap(grid.getGrid());
}
