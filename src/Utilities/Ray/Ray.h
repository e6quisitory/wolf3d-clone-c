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

Ray     Ray_New               (const Point2 origin, const Vec2 direction);
double  Ray_xAt               (const Ray r, const double y);
double  Ray_yAt               (const Ray r, const double x);
int     Ray_nextX             (const Ray r, const Point2 currPt);
int     Ray_nextY             (const Ray r, const Point2 currPt);
double  Ray_RayDist_dx        (const Ray r, const double dx);
double  Ray_RayDist_dy        (const Ray r, const double dy);
Point2  Ray_NextXIntrscPoint  (const Ray r, const Point2 currPt);
Point2  Ray_NextYIntrscPoint  (const Ray r, const Point2 currPt);
double  Ray_DistToPoint       (const Ray r, const Point2 pt);