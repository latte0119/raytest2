#include <memory>

#include "camera.hpp"
#include "image.hpp"
#include "vec3.hpp"
using namespace rayt;

vec3 color(const Ray &r) {
    const vec3 d = normalize(r.direction);
    double y = (d.y + 1) / 2.0;
    return mix(vec3(1.0), vec3(0.5, 0.7, 1.0), y);
}

int main() {
    const int width = 200;
    const int height = 100;

    std::unique_ptr<NormalCamera> c(new NormalCamera(vec3(0.0),
                                                     vec3(0.0, 0.0, -1.0),
                                                     vec3(0.0, 1.0, 0.0),
                                                     90.0, 2.0));

    std::cerr << c->position << std::endl;
    std::cerr << c->axisU << std::endl;
    std::cerr << c->axisV << std::endl;
    std::cerr << c->originUV << std::endl;

    Image img(width, height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            const double v = 1.0 * y / height;
            const double u = 1.0 * x / width;
            img.setPixel(x, y, color(c->getRay(u, v)));
        }
    }

    img.outputImageAsPPM();
}