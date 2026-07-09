#include "camera.h"
#include "color.h"
#include "hittable.h"
#include "hittable_list.h"
#include "interval.h"
#include "rtweekend.h"
#include "sphere.h"
#include "vec3.h"
#include <memory>

int main() {
  // world

  hittable_list world;
  world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
  world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));
  camera camera;
  camera.render(world);
}
