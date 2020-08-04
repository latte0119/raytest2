#include "geometry/vec3.hpp"
#include "image.hpp"
int main() {
    const int width = 100;
    const int height = 100;

    rayt::Image img(width, height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double r = 1.0 * y / height;
            double g = 1.0 * x / width;
            double b = 1.0;
            img.setPixel(x, y, geometry::vec3(r, g, b));
        }
    }

    img.outputImageAsPPM();
}