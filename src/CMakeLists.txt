cmake_minimum_required(VERSION 3.25)
project(wolf3d-clone-c C)

set(CMAKE_C_STANDARD 11)

# Find SDL2
find_package(SDL2 REQUIRED COMPONENTS SDL2)

include_directories(Vec2, Map, StringLib)

add_executable(wolf3d-clone-c
               Vec2/Vec2.c
               Map/Map.c
               StringLib/StringLib.c
               main.c)

# Link SDL2
target_link_libraries(wolf3d-clone-c PRIVATE SDL2::SDL2)
