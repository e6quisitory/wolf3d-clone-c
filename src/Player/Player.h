#pragma once

#include "../InputsBuffer/InputsBuffer.h"
#include "../Map/Map.h"

typedef struct {
    Point2 location;
    Vec2   viewDir;
    Vec2   east;
    Vec2   west;
    Vec2   south;
    int    refresh_rate;
} Player;

Player  Player_New     (Point2 location, int refresh_rate);
void    Player_Update  (Player* p, InputsBuffer* buffer, Map* map);