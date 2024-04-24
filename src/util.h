#pragma once

#include "flecs.h"
#include "raylib.h"

#include "components.h"

struct RenderContext
{
    flecs::query<const Position, const Renderable>* render_query;
    Texture2D sprites;
};
