#pragma once
#include "color.h"
#include "hittable.h"
#include "hittable_list.h"
#include "rtweekend.h"
#include "vec3.h"
class camera {
public:
  double aspect_radio = 1.0;
  double image_width = 1920;
  int samples_per_pixel = 10;

  camera() { initialize(); }

  void render(const hittable_list &world) {
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for (int i = 0; i < image_height; i++) {
      std::clog << "\rRow Remaining: " << image_height - i << ' ' << std::flush;
      for (int j = 0; j < image_width; j++) {
        color pixels_color = color(0, 0, 0);
        for (int sample_num = 0; sample_num < samples_per_pixel; sample_num++) {
          auto sample_ray = get_ray(i, j);
          pixels_color += pixel_sample_scale * ray_to_color(sample_ray, world);
        }


        write_pixels(std::cout, pixels_color);
      }
    }
    std::clog << "Done!\n";
  }

private:
  double image_height;
  point3 camera_center;
  point3 pixel_center;
  point3 viewport_upper_left;
  double pixel_sample_scale;
  vec3 pixel_delta_v;
  vec3 pixel_delta_u;

  void initialize() {
    image_height = image_width / aspect_radio;
    image_height = (image_height > 1) ? image_height : 1;
    int focal_length = 1;
    double viewport_height = 2.0;
    pixel_sample_scale = 1.0 / samples_per_pixel;
    double viewport_width =
        viewport_height * (double(image_width) / image_height);
    camera_center = point3(0, 0, 0);

    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);
    pixel_delta_u = viewport_u / image_width;
    pixel_delta_v = viewport_v / image_height;

    viewport_upper_left = camera_center - point3(0, 0, focal_length) -
                          0.5 * viewport_u - 0.5 * viewport_v;
    pixel_center =
        viewport_upper_left + 0.5 * pixel_delta_u + 0.5 * pixel_delta_v;
  }
  ray get_ray(int i, int j) {
    auto offset = random_range();
    auto newpixel = pixel_center + (j + offset.x()) * pixel_delta_u +
                    (i + offset.y()) * pixel_delta_v;
    auto dir = newpixel - camera_center;
    return ray(camera_center, dir);
  }
  color ray_to_color(const ray &r, const hittable_list &world) {
    hit_record record;
    if (world.hit(r, interval(0, infinity), record)) {
      return 0.5 * (record.normal + color(1, 1, 1));
    }
    vec3 d = unit_vector(r.direction());

    auto a = 0.5 * (d.y() + 1.0);

    return (1 - a) * color(1, 1, 1) + a * color(0.5, 0.7, 1);
  }
  vec3 random_range() {
    return vec3(random_double() - 0.5, random_double() - 0.5, 0);
  }
};
