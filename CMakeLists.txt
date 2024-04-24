cmake_minimum_required(VERSION 3.16)
project(basic-roguelike)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(dependencies/raylib)
add_subdirectory(dependencies/flecs)

add_executable(basic-roguelike
    src/systems/core.cpp
    src/main.cpp
)

target_link_libraries(basic-roguelike raylib flecs_static)
