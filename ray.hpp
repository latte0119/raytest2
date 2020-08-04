#pragma once
#include "vec3.hpp"

namespace rayt {
class Ray {
   public:
    Ray(const vec3& origin_, const vec3& direction_)
        : origin(origin_),
          direction(direction_) {}

    vec3 origin, direction;
};
}  // namespace rayt