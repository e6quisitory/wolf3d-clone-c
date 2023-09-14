#pragma once

#include "../Vec2/Vec2.h"
#include "../Conventions.h"

typedef struct {
    Point2 origin;
    Vec2 direction;

    xDir_t xDir;
    yDir_t yDir;
    iVec2  xDirVec;
    iVec2  yDirVec;

    double xStep;
    double yStep;

    double dxConst;
    double dyConst;
} Ray;

Ray     Ray_New               (Point2 origin, Vec2 direction);
double  Ray_xAt               (Ray* r, double y);
double  Ray_yAt               (Ray* r, double x);
int     Ray_nextX             (Ray* r, Point2 currPt);
int     Ray_nextY             (Ray* r, Point2 currPt);
double  Ray_RayDist_dx        (Ray* r, double dx);
double  Ray_RayDist_dy        (Ray* r, double dy);
Point2  Ray_NextXIntrscPoint  (Ray* r, Point2 currPt);
Point2  Ray_NextYIntrscPoint  (Ray* r, Point2 currPt);
double  Ray_DistToPoint       (Ray* r, Point2 pt);