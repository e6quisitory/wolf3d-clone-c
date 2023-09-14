#include "Multimedia.h"

Multimedia Multimedia_Init(int width, int height, double fov) {
    Multimedia mm;

    // Wimdow specs
    mm.windowWidth = width;
    mm.windowHeight = height;

    // SDL stuff
    SDL_Init(SDL_INIT_EVERYTHING);
    mm.window = SDL_CreateWindow("Wolfenstein 3D Clone", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    mm.renderer = SDL_CreateRenderer(mm.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
    SDL_RaiseWindow(mm.window);
    SDL_SetWindowInputFocus(mm.window);
    SDL_SetWindowMouseGrab(mm.window, SDL_TRUE);
    SDL_ShowCursor(SDL_DISABLE);
    SDL_SetRelativeMouseMode(SDL_TRUE);

    // Calculate casting ray angles
    double projectionPlaneWidth = 2 * tan(DegreesToRadians(fov / 2));
    double segmentLength = projectionPlaneWidth / mm.windowWidth;
    mm.castingRayAngles = (double*)malloc(mm.windowWidth*sizeof(double));
    mm.castingRayAngles_cos = (double*)malloc(mm.windowWidth*sizeof(double));
    for (int i = 0; i < mm.windowWidth; ++i) {
        double angle = atan(-(i * segmentLength - (projectionPlaneWidth / 2)));
        mm.castingRayAngles[i] = angle;
        mm.castingRayAngles_cos[i] = cos(angle);
    }

    return mm;
}

void Multimedia_Cleanup(Multimedia* mm) {
    // SDL cleanup
    SDL_DestroyRenderer(mm->renderer);
    SDL_DestroyWindow(mm->window);
    SDL_Quit();

    // Casting ray angle arrays
    free(mm->castingRayAngles);
    free(mm->castingRayAngles_cos);
}