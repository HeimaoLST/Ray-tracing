#pragma once

#include "hittable.h"
#include "interval.h"
#include "vec3.h"
#include <cmath>
class sphere : public hittable {
public:
  sphere(point3 center, double radius)
      : center(center), radius(std::fmax(0, radius)) {}
  bool hit(const ray &r, interval range,
           hit_record &record) const override {
    auto co = center - r.origin();
    auto direction = r.direction();
    auto a = dot(direction, direction);
    auto h = dot(direction, co);
    auto c = co.length_square() - radius * radius;
    auto discriminant = h * h - a * c;
    if (discriminant < 0) {
      return false;
    }
    auto sqrt_d = std::sqrt(discriminant);

    auto root = (h - sqrt_d) / a;
    if (range.outside_the_interval(root)) {
      root = (h + sqrt_d) / a;
      if (range.outside_the_interval(root)) {
        return false;
      }
    }
    record.t = root;
    record.p = r.at(root);
    record.normal = (record.p - center) / radius;
    if (dot(r.direction(), record.normal) > 0.0) {
      record.normal = -record.normal;
      record.face_front = false;
    } else {
      record.face_front = true;
    }
    return true;
  }

private:
  point3 center;
  double radius;
};
