#pragma once
#include "geometry/vec3.hpp"

namespace rayt {
using namespace geometry;
class Ray {
    Ray(const vec3& origin_, const vec3& direction_)
        : origin(origin_),
          direction(direction_) {}

   private:
    vec3 origin, direction;
};
}  // namespace rayt