#pragma once

#include <iostream>
#include <memory>

#include "geometry/vec3.hpp"

namespace rayt {
using namespace geometry;
class Image {
   public:
    Image(const int width_, const int height_)
        : width(width_),
          height(height_),
          pixels(new Pixel[width_ * height_]) {}

    inline void setPixel(const int x, const int y, vec3 a) {
        a = clamp(a, vec3(0.0), vec3(1.0));

        const int idx = y * width + x;
        pixels[idx] = Pixel(
            static_cast<unsigned char>(a.x * 255),
            static_cast<unsigned char>(a.y * 255),
            static_cast<unsigned char>(a.z * 255));
    }

    void outputImageAsPPM() {
        std::cout << "P3" << std::endl;
        std::cout << width << " " << height << std::endl;
        std::cout << 255 << std::endl;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                const int idx = y * width + x;
                std::cout << int(pixels[idx].r) << " " << int(pixels[idx].g) << " " << int(pixels[idx].b) << std::endl;
            }
        }
    }

   private:
    class Pixel {
       public:
        unsigned char r, g, b;
        Pixel(unsigned char r_ = 0, unsigned char g_ = 0, unsigned char b_ = 0) : r(r_), g(g_), b(b_) {}
    };

    const int width;
    const int height;
    std::unique_ptr<Pixel[]> pixels;
};
}  // namespace rayt
