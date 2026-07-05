#pragma once
#include "vec3.h"

class ray {

public:
  ray() {}
  ray at(double t) { return; }

private:
  point3 orig;
  vec3 dir;
}
