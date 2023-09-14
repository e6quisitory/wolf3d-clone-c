#include "Map/Map.h"
#include "Multimedia/Multimedia.h"

int main(int argc, char** argv) {

    Map map = InjestMap("assets/map.csv");
    PrintMap(&map);

    Multimedia multimedia = Multimedia_Init();

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

    Multimedia_Cleanup(&multimedia);
    FreeMapTiles(&map);

    return 0;
}
