cmake_minimum_required(VERSION 3.25)
project(wolf3d-clone-c C)

set(CMAKE_C_STANDARD 11)

# Find SDL2
find_package(SDL2 REQUIRED COMPONENTS SDL2)

# Add .c files into executable
file (GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/*.c"
                             "${CMAKE_SOURCE_DIR}/*/**/*.c"
                             )

add_executable (wolf3d-clone-c ${SRC_FILES})

# Create pre-compiled header
file (GLOB_RECURSE UTIL_HEADERS "${CMAKE_SOURCE_DIR}/Utilities/*.h")
target_precompile_headers (wolf3d-clone-c PRIVATE "Utilities/COMMON_HEADERS.h" ${UTIL_HEADERS})

# Link SDL2
target_link_libraries(wolf3d-clone-c PRIVATE SDL2::SDL2)
