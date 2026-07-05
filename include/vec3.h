
#pragma once

class vec3 {
public:
  double e[3];

  vec3() : e{0, 0, 0} {}
  vec3(double e1, double e2, double e3) : e{e1, e2, e3} {}
  double x() const { return e[0]; }
  double y() const { return e[1]; }
  double z() const { return e[2]; }

  vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
  vec3 &operator+=(const vec3 &u) {
    e[0] += u.e[0];
    e[1] += u.e[1];
    e[2] += u.e[2];
    return *this;
  }
  vec3 &operator-=(const vec3 &u) {
    e[0] -= u.e[0];
    e[1] -= u.e[1];
    e[2] -= u.e[2];
    return *this;
  }

  vec3 &operator/=(const double &u) {
    e[0] /= u;
    e[1] /= u;
    e[2] /= u;
    return *this;
  }

  vec3 operator+(const vec3 &u) {
    return vec3(e[0] + u.e[0], e[1] + u.e[1], e[2] + u.e[2]);
  }
};
using point3 = vec3;
