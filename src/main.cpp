#include "color.h"
#include "ray.h"
#include "vec3.h"
#include <iostream>
color ray_to_color(const ray &r) {
  vec3 d = unit_vector(r.direction());

  auto a = 0.5 * (d.y() + 1.0);

  return (1 - a) * color(1, 1, 1) + a * color(0.5, 0.7, 1);
}
int main() {
  double radio = 16.0 / 9.0;

  int image_width = 400;
  int image_height = image_width / radio;
  image_height = (image_height > 1) ? image_height : 1;

  int focal_length = 1;
  double viewport_height = 2.0;
  double viewport_width =
      viewport_height * (double(image_width) / image_height);
  auto camera_center = point3(0, 0, 0);

  auto viewport_u = vec3(viewport_width, 0, 0);
  auto viewport_v = vec3(0, -viewport_height, 0);
  auto pixel_delta_u = viewport_u / image_width;
  auto pixel_delta_v = viewport_v / image_height;

  point3 viewport_upper_left = camera_center - point3(0, 0, focal_length) -
                               0.5 * viewport_u - 0.5 * viewport_v;
  point3 pixel_center =
      viewport_upper_left + 0.5 * pixel_delta_u + 0.5 * pixel_delta_v;
  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
  for (int i = 0; i < image_height; i++) {
    std::clog << "\rRow Remaining: " << image_height - i << ' ' << std::flush;
    for (int j = 0; j < image_width; j++) {
      auto new_pixel_center =
          pixel_center + i * pixel_delta_v + j * pixel_delta_u;

      auto r = ray(camera_center, new_pixel_center - camera_center);

      auto pixel = ray_to_color(r);

      write_pixels(std::cout, pixel);
    }
  }
  std::clog << "Done!\n";
}
