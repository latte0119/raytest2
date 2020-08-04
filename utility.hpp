#pragma once
#include <algorithm>
#include <cmath>

namespace rayt {
extern const double PI = acos(-1);
extern const double EPS = 1e-6;

inline int sign(const double x) {
    if (x > EPS) return 1;
    if (x < -EPS) return -1;
    return 0;
}

inline double radians(const double deg) {
    return deg / 180.0 * PI;
}

inline double degrees(const double rad) {
    return rad / PI * 180.0;
}

inline double clamp(const double x, const double minv, const double maxv) {
    return std::max(std::min(x, maxv), minv);
}

inline double mix(const double x, const double y, const double a) {
    return x * (1 - a) + y * a;
}

}  // namespace rayt