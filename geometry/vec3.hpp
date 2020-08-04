#ifndef VEC3_H
#define VEC3_H
#include <cmath>
#include <iostream>

namespace geometry {
class vec3 {
   public:
    double x;
    double y;
    double z;

    vec3() : x(0), y(0), z(0) {}
    vec3(double _x) : x(_x), y(_x), z(_x) {}
    vec3(double _x, double _y, double _z) : x(_x), y(_y), z(_z){};

    vec3 &operator+=(const vec3 &a) {
        x += a.x;
        y += a.y;
        z += a.z;
        return *this;
    }

    vec3 &operator-=(const vec3 &a) {
        x -= a.x;
        y -= a.y;
        z -= a.z;
        return *this;
    }

    vec3 &operator*=(const vec3 &a) {
        x *= a.x;
        y *= a.y;
        z *= a.z;
        return *this;
    }
    vec3 &operator/=(const vec3 &a) {
        x /= a.x;
        y /= a.y;
        z /= a.z;
        return *this;
    }
};

inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

inline vec3 operator/(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}

inline vec3 operator+(const vec3 &v, double k) {
    return vec3(v.x + k, v.y + k, v.z + k);
}

inline vec3 operator+(double k, const vec3 &v) {
    return v + k;
}

inline vec3 operator-(const vec3 &v, double k) {
    return vec3(v.x - k, v.y - k, v.z - k);
}

inline vec3 operator-(double k, const vec3 &v) {
    return vec3(k - v.x, k - v.y, k - v.z);
}

inline vec3 operator*(const vec3 &v, double k) {
    return vec3(v.x * k, v.y * k, v.z * k);
}

inline vec3 operator*(double k, const vec3 &v) {
    return v * k;
}

inline vec3 operator/(const vec3 &v, double k) {
    return vec3(v.x / k, v.y / k, v.z / k);
}

inline vec3 operator/(double k, const vec3 &v) {
    return vec3(k / v.x, k / v.y, k / v.z);
}

inline double dot(const vec3 &v1, const vec3 &v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline vec3 cross(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}

inline double length2(const vec3 &v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

inline double length(const vec3 &v) {
    return sqrt(length2(v));
}

inline vec3 normalize(const vec3 &v) {
    return v / length(v);
}

std::ostream &operator<<(std::ostream &stream, const vec3 &v) {
    stream << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return stream;
}

vec3 clamp(const vec3 &a, const vec3 &minv, const vec3 &maxv) {
    return vec3(std::max(std::min(a.x, maxv.x), minv.x),
                std::max(std::min(a.y, maxv.y), minv.y),
                std::max(std::min(a.z, maxv.z), minv.z));
}

inline void orthonormalBasis(const vec3 &v1, vec3 &v2, vec3 &v3) {
    if (std::abs(v1.x) > 0.9)
        v2 = vec3(0, 1, 0);
    else
        v2 = vec3(1, 0, 0);

    v2 = normalize(v2 - dot(v1, v2) * v1);
    v3 = cross(v1, v2);
}
}  // namespace geometry

#endif