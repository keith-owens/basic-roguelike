#pragma once

#include "flecs.h"
#include "raylib.h"

#include "../components.h"
#include "../util.h"

namespace systems
{
    void startup(flecs::iter it);
    void check_close(flecs::iter it);
    void render(flecs::iter it);
} // namespace systems
