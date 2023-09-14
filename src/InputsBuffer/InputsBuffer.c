#include "InputsBuffer.h"

int GetXrel() {
    int currXrel;
    SDL_GetRelativeMouseState(&currXrel, NULL);
    return currXrel;
}

void BufferInputs(InputsBuffer* buffer, const Uint8* keyboardState) {

    /************************* Mouse movement *************************/

    SDL_Event currPendingEvent;
    int currXrel = 0;
    while (SDL_PollEvent(&currPendingEvent)) {
        if (currPendingEvent.type == SDL_MOUSEMOTION) {
            currXrel = currPendingEvent.motion.xrel;
            if (currXrel > 0) {
                buffer->lookCommand = LOOK_RIGHT;
            } else if (currXrel < 0) {
                buffer->lookCommand = LOOK_LEFT;
            }
            buffer->mouseAbsXrel = abs(currXrel);
        }
    }

    // Detect when mouse is not moving anymore and reset xrel and looking command (to prevent player spin)
    static int prevXrel = 0;
    if (currXrel == prevXrel && GetXrel() == 0) {
        buffer->mouseAbsXrel = 0;
        buffer->lookCommand = LOOK_NONE;
    }
    prevXrel = currXrel;

    /************************* W, A, S, D (to move player) *************************/

    bool north        = keyboardState[SDL_SCANCODE_W];
    bool south        = keyboardState[SDL_SCANCODE_S];
    bool east         = keyboardState[SDL_SCANCODE_D];
    bool west         = keyboardState[SDL_SCANCODE_A];
    bool northEast    = north && east;
    bool northWest    = north && west;
    bool southEast    = south && east;
    bool southWest    = south && west;

    if        (northEast)   buffer->moveCommand  = MOVE_NORTHEAST;
    else if   (northWest)   buffer->moveCommand  = MOVE_NORTHWEST;
    else if   (southEast)   buffer->moveCommand  = MOVE_SOUTHEAST;
    else if   (southWest)   buffer->moveCommand  = MOVE_SOUTHWEST;
    else if   (north)       buffer->moveCommand  = MOVE_NORTH;
    else if   (south)       buffer->moveCommand  = MOVE_SOUTH;
    else if   (west)        buffer->moveCommand  = MOVE_WEST;
    else if   (east)        buffer->moveCommand  = MOVE_EAST;
    else                    buffer->moveCommand  = MOVE_NONE;

    /************************* Spacebar (to open doors) *************************/

    buffer->doorCommand = keyboardState[SDL_SCANCODE_SPACE] ? DOOR_OPEN : DOOR_NONE;

    /************************* Escape (to exit game) *************************/

    buffer->quit = keyboardState[SDL_SCANCODE_ESCAPE];
}