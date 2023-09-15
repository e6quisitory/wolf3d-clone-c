#pragma once

#include "../InputsBuffer/InputsBuffer.h"
#include "../Map/Map.h"

typedef struct {
    Point2 location;
    Vec2   viewDir;
    Vec2   east;
    Vec2   west;
    Vec2   south;
} Player;

Player  Player_New     (Point2 location);
void    Player_Update  (Player* p, InputsBuffer* buffer, Map* map);