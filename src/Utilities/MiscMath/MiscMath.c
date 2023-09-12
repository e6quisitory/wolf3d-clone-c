#include "MiscMath.h"

double GetDecimal(const double d) {
    double d_abs = fabs(d);
    return d_abs - floor(d_abs);
}

double IsInteger(const double d) {
    if (GetDecimal(d) == 0.0) {
        return true;
    } else {
        return false;
    }
}

double DegreesToRadians(const double degrees) {
    return degrees*M_PI/180.0;
}