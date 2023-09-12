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

RayCursor RayCursor_New(Ray ray, Point2 hitPoint);