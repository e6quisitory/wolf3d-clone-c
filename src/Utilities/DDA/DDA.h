#pragma once

#include "../Ray/Ray.h"
#include "../Vec2/Vec2.h"

typedef enum {
    WALL_TYPE_HORIZONTAL,
    WALL_TYPE_VERTICAL,
    WALL_TYPE_CORNER,
    WALL_TYPE_NONE
} wallType_t;

typedef struct {
    Ray        ray;
    Point2     hitPoint;
    iPoint2    hitTile;
    wallType_t wallType;
    double     widthPercent;
} RayCursor;

RayCursor   RC_New                   (Ray* ray, Point2 hitPoint);
void        RC_CalculateWallHitInfo  (RayCursor* rc);
void        RC_ClearWallHitInfo      (RayCursor* rc);
wallType_t  RC_GetWallType           (RayCursor* rc);
double      RC_GetWidthPercent       (RayCursor* rc);
void        RC_GoToNextHit           (RayCursor* rc);
void        RC_GoToNextCenterHit     (RayCursor* rc);
double      RC_GetDistToHitPoint     (RayCursor* rc);
