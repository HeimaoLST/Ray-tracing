#pragma once
#include "vec3.h"


class ray {

public:
  ray() {}

  ray(const point3& point, const vec3& d) : orig(point), dir(d) {}
  vec3 direction() const {
      return dir;
  }
  point3 at(double t) { return orig  + t * dir; }

private:
  point3 orig;
  vec3 dir;
};
