#include "raylib.h"
#include "flecs.h"

#include "systems/core.h"
#include "components.h"
#include "util.h"

void register_systems(flecs::world& world, RenderContext* render_context)
{
    // Pipelines in flecs:
    // The systems in flecs are ordered by the phase that is assigned to them with .kind()
    // OnStart - A special phase that is run on the first frame
    // OnLoad - Load data in ECS. Example is loading keyboard and mouse inputs.
    // PostLoad - Process data. Example is associating keypresses with higher level actions.
    // PreUpdate - In between input processing and processing game logic. Example is preparing the frame or cleaning up things from the previous frame.
    // OnUpdate - Gameplay systems. Default phase that is used if phase is not specified.
    // OnValidate - Validate the state of the game. Example would be collision detection.
    // PostUpdate - Apply corrections. Example is moving entities that were detected to be overlapping in collision detection.
    // PreStore - Prepare for rendering. Example is calulating transform matrices from a scene graph.
    // OnStore - Render frame.

    world.system("start")
        .kind(flecs::OnStart)
        .ctx(render_context)
        .iter(systems::startup);

    world.system("check_close")
        .kind(flecs::OnLoad)
        .iter(systems::check_close);

    world.system("render")
        .kind(flecs::OnStore)
        .ctx(render_context)
        .iter(systems::render);
}

int main(int argc, char* args[])
{
    flecs::world world;

    flecs::query<const Position, const Renderable> rendering_query = world.query<const Position, const Renderable>();
    Texture2D spritesheet = { NULL };
    RenderContext render_context = { &rendering_query, spritesheet};

    register_systems(world, &render_context);

    while (world.progress()) {}

    if (IsTextureReady(spritesheet))
    {
        UnloadTexture(spritesheet);
    }
    CloseWindow();
    return 0;
}