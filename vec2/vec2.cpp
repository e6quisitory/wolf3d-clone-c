#include "vec2.h"

Vec2 Vec2_Add(Vec2 v1, Vec2 v2) {
    Vec2 result;
         result.e[0] = v1.e[0] + v2.e[0];
         result.e[1] = v1.e[1] + v2.e[1];
    return result;
}

Vec2 Vec2_Subtract(Vec2 v1, Vec2 v2) {
    Vec2 result;
         result.e[0] = v1.e[0] - v2.e[0];
         result.e[1] = v1.e[1] - v2.e[1];
    return result;
}

Vec2 Vec2_Scale(double scaleFactor, Vec2 v) {
    Vec2 result;
         result.e[0] = scaleFactor*v.e[0];
         result.e[1] = scaleFactor*v.e[1];
    return result;
}

double Vec2_Dot(Vec2 v1, Vec2 v2) {
    return v1.e[0]*v2.e[0] + v1.e[1]*v2.e[1];
}