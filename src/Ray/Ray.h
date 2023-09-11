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