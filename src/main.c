#include "Map/Map.h"
#include "Multimedia/Multimedia.h"
#include "Player/Player.h"

void RenderFrame(Multimedia* mm, Player* p, Map* map) {
    SDL_SetRenderDrawColor(mm->renderer, 0,0,0,255);
    SDL_RenderClear(mm->renderer);
    for (int x = 0; x < mm->windowWidth; ++x) {
        Vec2 currRayDir = Vec2_Rotate(p->viewDir, mm->castingRayAngles[x]);
        Ray currRay = Ray_New(p->location, currRayDir);
        RayCursor rc = RC_New(&currRay, p->location);
        while ((rc.hitTile.x >= 0 && rc.hitTile.x < map->width) && (rc.hitTile.y >= 0 && rc.hitTile.y < map->height)) {
            RC_GoToNextHit(&rc);
            if (GetTile(map, rc.hitTile) == 1) {
                double dist = RC_GetDistToHitPoint(&rc);
                double renderHeight = 550.0/(dist*mm->castingRayAngles_cos[x]);
                if (RC_GetWallType(&rc) == WALL_TYPE_VERTICAL) {
                    SDL_SetRenderDrawColor( mm->renderer, 200, 0, 0, 255 );
                } else {
                    SDL_SetRenderDrawColor( mm->renderer, 0, 0, 200, 255 );
                }
                int y = (mm->windowHeight / 2) - (int)(renderHeight / 2.0);
                SDL_Rect slice = {x, y, 1, (int)renderHeight};
                SDL_RenderFillRect(mm->renderer, &slice);
                break;
            } else {
                continue;
            }
        }
    }
    SDL_RenderPresent(mm->renderer);
}

int main(int argc, char** argv) {
    Map map = InjestMap("assets/map.csv");
    Multimedia multimedia = Multimedia_Init(1280, 720, 90.0);
    Player player = Player_New(Point2_New(8.01, 2.56));
    Vec2_Print(player.location);
    iPoint2_Print(Point2_to_iPoint2(player.location));
    printf("%d\n", GetTile(&map, Point2_to_iPoint2(player.location)));
    InputsBuffer buffer;
    const Uint8* keyboardState = SDL_GetKeyboardState(NULL);

    while (1) {
        BufferInputs(&buffer, keyboardState);
        Player_Update(&player, &buffer, &map);
        RenderFrame(&multimedia, &player, &map);
        if (buffer.quit) break;
    }

    Multimedia_Cleanup(&multimedia);
    FreeMapTiles(&map);

    return 0;
}
