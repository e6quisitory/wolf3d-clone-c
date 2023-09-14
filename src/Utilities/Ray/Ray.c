#include "Ray.h"

Ray Ray_New(Point2 origin, Vec2 dir) {
    Ray r;
    
    r.origin = origin;
    r.direction = UnitVector(dir);
    r.dxConst = sqrt(1.0+pow(dir.y/dir.x, 2.0));
    r.dyConst = sqrt(1.0+pow(dir.x/dir.y, 2.0));
    
    if (dir.x > 0.0)
        r.xDir = X_DIR_EAST;
    else
        r.xDir = X_DIR_WEST;

    if (dir.y > 0.0)
        r.yDir = Y_DIR_NORTH;
    else
        r.yDir = Y_DIR_SOUTH;

    r.xDirVec = iVec2_New(r.xDir, 0);
    r.yDirVec = iVec2_New(0, r.yDir);

    r.xStep = sqrt(pow(r.dyConst, 2.0) - 1.0);
    r.yStep = sqrt(pow(r.dxConst, 2.0) - 1.0);

    return r;
}

double Ray_xAt(Ray *r, double y) {
    return r->origin.x + ((y-r->origin.y)/r->direction.y)*r->direction.x;
}

double Ray_yAt(Ray *r, double x) {
    return r->origin.y + ((x-r->origin.x)/r->direction.x)*r->direction.y;
}

int Ray_nextX(Ray* r, Point2 currPt){
    if (!IsInteger(currPt.x)) {
        switch (r->xDir) {
            case X_DIR_EAST: return (int)ceil(currPt.x);
            case X_DIR_WEST: return (int)floor(currPt.x);
            case X_DIR_NONE: return -1;
        }
    } else {
        return (int)currPt.x + r->xDir;
    }
}

int Ray_nextY(Ray* r, Point2 currPt){
    if (!IsInteger(currPt.y)) {
        switch (r->yDir) {
            case Y_DIR_NORTH: return (int)ceil(currPt.y);
            case Y_DIR_SOUTH: return (int)floor(currPt.y);
            case Y_DIR_NONE:  return -1;

        }
    } else {
        return (int)currPt.y + r->yDir;
    }
}

double Ray_RayDist_dx(Ray* r, double dx) {
    return fabs(dx)*r->dxConst;
}

double Ray_RayDist_dy(Ray* r, double dy) {
    return fabs(dy)*r->dyConst;
}

Point2 Ray_NextXIntrscPoint(Ray* r, Point2 currPt) {
    double nextXVal = Ray_nextX(r, currPt);
    return Point2_New(nextXVal, Ray_yAt(r, nextXVal));
}

Point2 Ray_NextYIntrscPoint(Ray* r, Point2 currPt) {
    double nextYVal = Ray_nextY(r, currPt);
    return Point2_New(Ray_xAt(r, nextYVal), nextYVal);
}

double Ray_DistToPoint(Ray* r, Point2 pt) {
    return Ray_RayDist_dx(r, pt.x - r->origin.x);
}
