#include "MiscMath.h"

double GetDecimal(double d) {
    double d_abs = fabs(d);
    return d_abs - floor(d_abs);
}

double IsInteger(double d) {
    if (GetDecimal(d) == 0.0) {
        return true;
    } else {
        return false;
    }
}

double DegreesToRadians(double degrees) {
    return degrees*M_PI/180.0;
}