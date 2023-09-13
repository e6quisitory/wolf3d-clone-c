#include "Map/Map.h"

int main(int argc, char** argv) {   

    Point2 origin = Point2_New(1.01, 1.01);
    Vec2 dir = Vec2_New(1.0, 0.5);
    Ray ray = Ray_New(origin, dir);
    RayCursor rc = RC_New(ray, origin);

    Point2_Print(rc.hitPoint);
    RC_GoToNextHit(&rc);
    Point2_Print(rc.hitPoint);
    RC_GoToNextHit(&rc);
    Point2_Print(rc.hitPoint);
    RC_GoToNextCenterHit(&rc);
    Point2_Print(rc.hitPoint);

//    Point2 p = Point2_New(0.5, 5.4);
//    Point2_Print(p);
//
//    iPoint2 ip = iPoint2_New(-1, 5);
//    iPoint2_Print(ip);
//
//    printf("CSV map file testing...\n");
//    Map map = InjestMap("assets/map.csv");
//    PrintMap(map);
//
//    printf("(1,2) -> %d\n", GetTile(map, 1, 2));
//    printf("(3,1) -> %d\n", GetTile(map, 3, 1));
//    printf("(3,4) -> %d\n", GetTile(map, 3, 4));
//
//    DestroyMap(map);
//    printf("\n");
//
//    printf("SDL testing testing...\n");
//
//    SDL_Init(SDL_INIT_EVERYTHING);
//
//    SDL_Window* window = SDL_CreateWindow("Wolfenstein 3D Clone", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
//    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//    SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
//
//    SDL_Event currPendingEvent;
//    bool quitFlag = false;
//
//    while (!quitFlag) {
//        while (SDL_PollEvent(&currPendingEvent)){
//            if (currPendingEvent.type == SDL_QUIT) {
//                quitFlag = true;
//                break;
//            }
//        }
//    }
//
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();

    return 0;
}
