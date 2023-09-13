#pragma once

/*
=========================================================
    Vec2
=========================================================
*/

typedef struct {
    double x;
    double y;
} Vec2;

Vec2    Vec2_New         (double x, double y);
Vec2    Vec2_Add         (Vec2 v1, Vec2 v2);
Vec2    Vec2_Subtract    (Vec2 v1, Vec2 v2);
Vec2    Vec2_Scale       (Vec2 v, double scaleFactor);
Vec2    Vec2_Negative    (Vec2 v);
double  Vec2_Dot         (Vec2 v1, Vec2 v2);
void    Vec2_Print       (Vec2 v);
double  Vec2_Length      (Vec2 v);
Vec2    Vec2_UnitVector  (Vec2 v);

/*
=========================================================
    Point2
=========================================================
*/

typedef Vec2 Point2;
#define Point2_New      Vec2_New
#define Point2_Add       Vec2_Add
#define Point2_Subtract Vec2_Subtract
#define Point2_Print    Vec2_Print

/*
=========================================================
    iVec2
=========================================================
*/

typedef struct {
    int x;
    int y;
} iVec2;

iVec2    iVec2_New       (int x, int y);
iVec2    iVec2_Add       (iVec2 v1, iVec2 v2);
iVec2    iVec2_Subtract  (iVec2 v1, iVec2 v2);
iVec2    iVec2_Negative  (iVec2 v);
void     iVec2_Print     (iVec2 v);

/*
=========================================================
    iPoint2
=========================================================
*/

typedef iVec2 iPoint2;
#define iPoint2_New       iVec2_New
#define iPoint2_Add        iVec2_Add
#define iPoint2_Subtract  iVec2_Subtract
#define iPoint2_Print     iVec2_Print

/*
=========================================================
    Conversions
=========================================================
*/

iVec2 Vec2_to_iVec2  (Vec2 v);
Vec2  iVec2_to_Vec2  (iVec2 v);
#define Point2_to_iPoint2  Vec2_to_iVec2
#define iPoint2_to_Point2  iVec2_to_Vec2
