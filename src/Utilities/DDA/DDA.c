#include "DDA.h"

RayCursor RC_New(Ray* ray, Point2 hitPoint) {
    RayCursor rc;
    rc.ray = *ray;
    rc.hitPoint = hitPoint;
    rc.hitTile = Point2_to_iPoint2(hitPoint);
    rc.widthPercent = -1.0;
    rc.wallType = WALL_TYPE_NONE;
    return rc;
}

void RC_CalculateWallHitInfo(RayCursor* rc) {
    double xDecimal = GetDecimal(rc->hitPoint.x);
    double yDecimal = GetDecimal(rc->hitPoint.y);
    bool xIsInt = xDecimal == 0.0;
    bool yIsInt = yDecimal == 0.0;
    bool xIsMiddle = xDecimal == 0.5;
    bool yIsMiddle = yDecimal == 0.5;

    if ((xIsInt || xIsMiddle) && !yIsInt) {
        rc->wallType = WALL_TYPE_VERTICAL;
        rc->widthPercent = yDecimal;
    } else if ((yIsInt || yIsMiddle) && !xIsInt) {
        rc->wallType = WALL_TYPE_HORIZONTAL;
        rc->widthPercent = xDecimal;
    } else if (xIsInt && yIsInt) {
        rc->wallType = WALL_TYPE_CORNER;
        rc->widthPercent = 0.0;
    } else {
        rc->wallType = WALL_TYPE_NONE;
        rc->widthPercent = -1.0;
    }
}

void RC_ClearWallHitInfo(RayCursor* rc) {
    rc->wallType = WALL_TYPE_NONE;
    rc->widthPercent = -1.0;
}

wallType_t RC_GetWallType(RayCursor* rc) {
    if (rc->widthPercent == -1.0) {
        RC_CalculateWallHitInfo(rc);
    }
    return rc->wallType;
}

double RC_GetWidthPercent(RayCursor* rc) {
    if (rc->widthPercent == -1.0) {
        RC_CalculateWallHitInfo(rc);
    }
    return rc->widthPercent;
}

void RC_GoToNextHit(RayCursor* rc) {
    Point2 nextX = Ray_NextXIntrscPoint(&rc->ray, rc->hitPoint);
    Point2 nextY = Ray_NextYIntrscPoint(&rc->ray, rc->hitPoint);

    double distNextX = Ray_DistToPoint(&rc->ray, nextX);
    double distNextY = Ray_DistToPoint(&rc->ray, nextY);

    if (distNextX < distNextY) {
        rc->hitPoint = nextX;
        rc->hitTile  = iPoint2_Add(rc->hitTile, rc->ray.xDirVec);
    } else if (distNextY < distNextX) {
        rc->hitPoint = nextY;
        rc->hitTile  = iPoint2_Add(rc->hitTile, rc->ray.yDirVec);
    } else {
        rc->hitPoint = nextX; // can be either nextX or nextY both will be the same
        rc->hitTile  = iPoint2_Add(rc->hitTile, iPoint2_Add(rc->ray.xDirVec, rc->ray.yDirVec));
    }

    RC_ClearWallHitInfo(rc);
}

RayCursor RC_GetNextHit(RayCursor rc) {
    RC_GoToNextHit(&rc);
    return rc;
}

void RC_GoToNextCenterHit(RayCursor* rc) {
    assert(GetDecimal(rc->hitPoint.x) == 0.0 || GetDecimal(rc->hitPoint.y) == 0.0);

    Vec2 vecToCenter;
    if (RC_GetWallType(rc) == WALL_TYPE_VERTICAL) {
        vecToCenter.x = (double)(rc->ray.xDir) / 2.0;
        vecToCenter.y = ((double)(rc->ray.yDir) * rc->ray.yStep) / 2.0;
    } else {
        vecToCenter.x = ((double)(rc->ray.xDir) * rc->ray.xStep) / 2.0;
        vecToCenter.y = (double)(rc->ray.yDir) / 2.0;
    }

    *rc = RC_New(&rc->ray, Point2_Add(rc->hitPoint, vecToCenter));
    RC_CalculateWallHitInfo(rc);
}

double RC_GetDistToHitPoint(RayCursor* rc) {
    return Ray_DistToPoint(&rc->ray, rc->hitPoint);
}

