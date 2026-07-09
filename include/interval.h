#pragma once

#include <limits>

class interval {
  static constexpr double pos_inf = std::numeric_limits<double>::infinity();
  static constexpr double neg_inf = -std::numeric_limits<double>::infinity();

public:
  interval() : min(pos_inf), max(neg_inf) {}
  interval(double const min, double const max) : min(min), max(max) {}
  bool within_the_interval(double num) const { return min <= num && num <= max; }
  bool outside_the_interval(double num) const { return num < min || num > max; }
  double min;
  double max;
   static const interval empty;
   static const interval universe;
   double clamp(double num) {
       if (num < min) return min;
       if (num > max) return max;
       return num;
   }
};
inline const interval interval::empty    = interval();
inline const interval interval::universe = interval(
    interval::neg_inf, interval::pos_inf
);
