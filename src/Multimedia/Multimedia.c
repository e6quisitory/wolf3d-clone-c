#include "Multimedia.h"

Multimedia Multimedia_Init() {
    Multimedia mm;
    SDL_Init(SDL_INIT_EVERYTHING);
    mm.window = SDL_CreateWindow("Wolfenstein 3D Clone", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
    mm.renderer = SDL_CreateRenderer(mm.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
    return mm;
}

void Multimedia_Cleanup(Multimedia* mm) {
    SDL_DestroyRenderer(mm->renderer);
    SDL_DestroyWindow(mm->window);
    SDL_Quit();
}