#include "raylib.h"
#include "game.h"


int main()
{
    InitWindow(1200, 900, "BOOMBERMAN");
    SetTargetFPS(60);

    Game myGame;

    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(DARKBLUE);
        myGame.render();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
