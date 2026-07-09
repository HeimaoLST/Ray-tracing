#pragma once
#include "interval.h"
#include "vec3.h"
#include <iostream>
#include <ostream>
using color = vec3;
inline void write_pixels(std::ostream &out, const color &pixel_color) {
  auto r = pixel_color.x();
  auto g = pixel_color.y();
  auto b = pixel_color.z();
   interval range =  interval(0.0, 1.0);
  int rbyte = int(255.99 * range.clamp(r));
  int gbyte = int(255.99 * range.clamp(g));
  int bbyte = int(255.99 * range.clamp(b));
  out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
