#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Vec2/Vec2.h"

typedef struct {
    int* tiles;
} Map;

void PrintMap(char* mapFileName) {
    FILE* mapFile = fopen(mapFileName, "r");

    if (mapFile == NULL) {
        printf("Map file could not be read.\n");
        exit(1);
    }

    char c;
    while (true) {
        c = fgetc(mapFile);
        if (c != EOF) {
            printf("%c", c);
        } else {
            printf("\n");
            break;
        }
    }
}

int main(int argc, char* argv[]) {

    // Test csv file reading
    PrintMap("map.csv");

    // Test Vec2 Library
    Vec2 v1 = Vec2_New(10.643, -3.442);
    Vec2 v2 = Vec2_New(-2.324, 4.255);
    Vec2_Print(v1);
    Vec2_Print(v2);
    Vec2_Print(Vec2_Add(v1, v2));
    Vec2_Print(Vec2_Scale(v2, 10.0));

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("Wolfenstein 3D Clone", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");

    SDL_Event currPendingEvent;
    bool quitFlag = false;

    while (!quitFlag) {
        while (SDL_PollEvent(&currPendingEvent)){
            if (currPendingEvent.type == SDL_QUIT) {
                quitFlag = true;
                break;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
