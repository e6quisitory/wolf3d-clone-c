/*
=========================================================
    Vec2
=========================================================
*/

typedef struct {
    double e[2];
} Vec2;

typedef Vec2 Point2;

Vec2    Vec2_New       (double x, double y);
Vec2    Vec2_Add       (Vec2 v1, Vec2 v2);
Vec2    Vec2_Subtract  (Vec2 v1, Vec2 v2);
Vec2    Vec2_Scale     (Vec2 v, double scaleFactor);
double  Vec2_Dot       (Vec2 v1, Vec2 v2);
void    Vec2_Print     (Vec2 v);

/*
=========================================================
    iVec2
=========================================================
*/

typedef struct {
    int e[2];
} iVec2;

typedef iVec2 iPoint2;

iVec2    iVec2_New       (int x, int y);
iVec2    iVec2_Add       (iVec2 v1, iVec2 v2);
iVec2    iVec2_Subtract  (iVec2 v1, iVec2 v2);
void     iVec2_Print     (iVec2 v);