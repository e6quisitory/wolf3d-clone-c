#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* tiles;
} Map;

Map InjestMap(char* mapFileName) {
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

    InjestMap("map.csv");

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
