#include "core.h"

void systems::startup(flecs::iter it)
{
    auto render_context = it.ctx<RenderContext>();

    InitWindow(80 * 16, 50 * 16, "Window");
    SetTargetFPS(60);
    // SetExitKey(NULL); // Used to remove the esc key as an exit key.

    // TODO: Need to make sure this loaded correctly.
    // Not sure how the function works under the hood. Might need to load the texture on another thread.
    render_context->sprites = LoadTexture("assets/sprites.png");

    flecs::entity player = it.world().entity("player")
        .set<Position>({40, 25})
        .set<Renderable>({&render_context->sprites, 25*16, 0, YELLOW});
}

void systems::check_close(flecs::iter it)
{
    if(WindowShouldClose())
    {
        // Note: When calling this function the *next* call to world.progress() will return false.
        // This means all of the systems that still need to be run will run as normal.
        it.world().quit();
    }
}

void systems::render(flecs::iter it)
{
    auto render_context = it.ctx<RenderContext>();

    BeginDrawing();
    ClearBackground(DARKGRAY);
    DrawFPS(10, 10);
    render_context->render_query->each([&](flecs::entity e, const Position& p, const Renderable& r) {
        Rectangle source = {(float)r.sprite_x, (float)r.sprite_y, 16.0f, 16.0f};
        Vector2 dest = {(float)p.x * 16, (float)p.y * 16};
        DrawTextureRec(*r.spritesheet, source, dest, r.color);
    });

    EndDrawing();
}