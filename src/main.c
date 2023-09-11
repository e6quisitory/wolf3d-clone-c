#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Vec2/Vec2.h"
#include "Map/Map.h"
#include "StringLib/StringLib.h"

int main(int argc, char** argv) {

    printf("Executable Path: %s\n", argv[0]);
    printf("executable path str len: %zu\n", strlen(argv[0]));
    size_t execPath_len = strlen(argv[0]);
    char* execPath = CreateEmptyStringN(execPath_len);
    strcpy(execPath, argv[0]);
    char* mapPath = JoinStrings(execPath, "/assets/map.csv");
    printf("map path: %s\n", mapPath);
    free(execPath);

    printf("String testing...\n");
    char* str = strdup("Hello, world");
    printf("%s\n", str);
    printf("%zu\n", strlen(str));
    str = AppendCharToString(str, '!');
    printf("%s\n", str);
    printf("%zu\n", strlen(str));
    printf("\n");

    char* str1 = strdup("hel");
    char* str2 = strdup("lo!");
    char* joined = JoinStrings(str1, str2);
    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    printf("Joined: %s\n", joined);
    free(str1);
    free(str2);
    free(joined);


    printf("Vec2 library testing...\n");
    Vec2 v1 = Vec2_New(10.643, -3.442);
    Vec2 v2 = Vec2_New(-2.324, 4.255);
    Vec2_Print(v1);
    Vec2_Print(v2);
    Vec2_Print(Vec2_Add(v1, v2));
    Vec2_Print(Vec2_Scale(v2, 10.0));
    printf("\n");

    printf("CSV map file testing...\n");
    Map map = InjestMap(mapPath);
    PrintMap(map);

    printf("(1,2) -> %d\n", GetTile(map, 1, 2));
    printf("(3,1) -> %d\n", GetTile(map, 3, 1));
    printf("(3,4) -> %d\n", GetTile(map, 3, 4));

    DestroyMap(map);
    printf("\n");

    printf("SDL testing testing...\n");

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
