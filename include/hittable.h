#pragma once

#include "interval.h"
#include "ray.h"
#include "vec3.h"

class hit_record {
public:
  point3 p;
  vec3 normal;
  double t;
  bool face_front;
};

class hittable {
public:
  virtual ~hittable() = default;
  virtual bool hit(const ray &r, interval range,
                   hit_record &record) const = 0;
};
