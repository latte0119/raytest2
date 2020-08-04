#pragma once

#include "ray.hpp"
#include "utility.hpp"
#include "vec3.hpp"
namespace rayt {
class Camera {
   public:
    /*
    0<=u,v<=1
    */
    virtual Ray getRay(const double u, const double v) const = 0;
};

class NormalCamera : public Camera {
   public:
    NormalCamera(const vec3& lookfrom, const vec3& lookat, const vec3& vup, double vfov, double aspect) {
        const vec3 Z = normalize(lookfrom - lookat);
        const vec3 X = normalize(cross(vup, Z));
        const vec3 Y = normalize(cross(Z, X));

        const double rad = radians(vfov);
        const double h = tan(rad / 2.0);
        const double w = h * aspect;

        axisU = 2.0 * w * X;
        axisV = 2.0 * h * Y;
        originUV = lookfrom - w * X - h * Y - Z;
        position = lookfrom;
    }
    Ray getRay(const double u, const double v) const override {
        return Ray(position, u * axisU + (1.0 - v) * axisV + originUV - position);
    }

    vec3 axisU, axisV, originUV, position;
};

}  // namespace rayt