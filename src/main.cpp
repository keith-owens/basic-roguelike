#include "raylib.h"
#include "flecs.h"

int main(int argc, char* argv)
{
    flecs::world world;

    InitWindow(800, 450, "Window");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("This is a window that was created with Raylib.", 170, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}