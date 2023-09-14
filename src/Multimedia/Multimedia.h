#pragma once

#include <SDL2/SDL.h>

typedef struct {
    SDL_Window*   window;
    SDL_Renderer* renderer;
} Multimedia;

Multimedia  Multimedia_Init     ();
void        Multimedia_Cleanup  (Multimedia* mm);