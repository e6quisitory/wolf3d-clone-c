#pragma once

typedef struct {
    int windowWidth;
    int windowHeight;
    int refresh_rate;

    double renderHeightProprConst;

    double fov;
    double* castingRayAngles;
    double* castingRayAngles_cos;

    SDL_Window*   window;
    SDL_Renderer* renderer;
} Multimedia;

Multimedia  Multimedia_Init     (int width, int height, double fov);
void        Multimedia_Cleanup  (Multimedia* mm);
