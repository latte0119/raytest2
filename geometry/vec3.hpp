#ifndef VEC3_H
#define VEC3_H
#include <cmath>
#include <iostream>

namespace geometry {
class Vec3 {
   public:
    double x;
    double y;
    double z;

    Vec3() : x(0), y(0), z(0) {}
    Vec3(double _x) : x(_x), y(_x), z(_x) {}
    Vec3(double _x, double _y, double _z) : x(_x), y(_y), z(_z){};

    Vec3 &operator+=(const Vec3 &a) {
        x += a.x;
        y += a.y;
        z += a.z;
        return *this;
    }

    Vec3 &operator-=(const Vec3 &a) {
        x -= a.x;
        y -= a.y;
        z -= a.z;
        return *this;
    }

    Vec3 &operator*=(const Vec3 &a) {
        x *= a.x;
        y *= a.y;
        z *= a.z;
        return *this;
    }
    Vec3 &operator/=(const Vec3 &a) {
        x /= a.x;
        y /= a.y;
        z /= a.z;
        return *this;
    }
};

inline Vec3 operator+(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

inline Vec3 operator-(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

inline Vec3 operator*(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

inline Vec3 operator/(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}

inline Vec3 operator+(const Vec3 &v, double k) {
    return Vec3(v.x + k, v.y + k, v.z + k);
}

inline Vec3 operator+(double k, const Vec3 &v) {
    return v + k;
}

inline Vec3 operator-(const Vec3 &v, double k) {
    return Vec3(v.x - k, v.y - k, v.z - k);
}

inline Vec3 operator-(double k, const Vec3 &v) {
    return Vec3(k - v.x, k - v.y, k - v.z);
}

inline Vec3 operator*(const Vec3 &v, double k) {
    return Vec3(v.x * k, v.y * k, v.z * k);
}

inline Vec3 operator*(double k, const Vec3 &v) {
    return v * k;
}

inline Vec3 operator/(const Vec3 &v, double k) {
    return Vec3(v.x / k, v.y / k, v.z / k);
}

inline Vec3 operator/(double k, const Vec3 &v) {
    return Vec3(k / v.x, k / v.y, k / v.z);
}

inline double dot(const Vec3 &v1, const Vec3 &v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline Vec3 cross(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}

inline double length2(const Vec3 &v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

inline double length(const Vec3 &v) {
    return sqrt(length2(v));
}

inline Vec3 normalize(const Vec3 &v) {
    return v / length(v);
}

std::ostream &operator<<(std::ostream &stream, const Vec3 &v) {
    stream << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return stream;
}

inline void orthonormalBasis(const Vec3 &v1, Vec3 &v2, Vec3 &v3) {
    if (std::abs(v1.x) > 0.9)
        v2 = Vec3(0, 1, 0);
    else
        v2 = Vec3(1, 0, 0);

    v2 = normalize(v2 - dot(v1, v2) * v1);
    v3 = cross(v1, v2);
}
}  // namespace geometry

#endif