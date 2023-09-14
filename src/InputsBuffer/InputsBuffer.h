#pragma once

#include <stdbool.h>

typedef enum {
    LOOK_RIGHT,
    LOOK_LEFT,
    LOOK_NONE
} lookCommand_t;

typedef enum {
    MOVE_NORTH,
    MOVE_SOUTH,
    MOVE_EAST,
    MOVE_WEST,
    MOVE_NORTHEAST,
    MOVE_NORTHWEST,
    MOVE_SOUTHEAST,
    MOVE_SOUTHWEST,
    MOVE_NONE
} moveCommand_t;

typedef enum {
    DOOR_OPEN,
    DOOR_NONE
} doorCommand_t;

typedef struct {
    lookCommand_t lookCommand;
    moveCommand_t moveCommand;
    doorCommand_t doorCommand;
    bool quit;

    // Mouse related
    int mouseAbsXrel;
    int prevXrel;
} InputsBuffer;

void BufferInputs(InputsBuffer* buffer, const Uint8* keyboardState);