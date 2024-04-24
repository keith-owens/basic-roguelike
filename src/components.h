#pragma once

#include "flecs.h"
#include "raylib.h"

struct Position
{
    int x;
    int y;
};

struct Renderable
{
    Texture2D* spritesheet;
    int sprite_x;
    int sprite_y;
    Color color;
};
