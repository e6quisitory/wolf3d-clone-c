#include "DDA.h"

RayCursor RayCursor_New(Ray ray, Point2 hitPoint) {
    RayCursor rc;
    rc.ray = ray;
    rc.hitPoint = hitPoint;
    rc.hitTile = Point2_to_iPoint2(hitPoint);
    rc.widthPercent = -1.0;
    rc.wallType = WALL_TYPE_NONE;

    return rc;
}

