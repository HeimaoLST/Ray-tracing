#pragma once

#include "hittable.h"
#include "interval.h"
#include "ray.h"
#include <memory>
#include <vector>
class hittable_list : public hittable {
public:
  std::vector<std::shared_ptr<hittable>> objects;
  hittable_list() {};
  hittable_list(std::shared_ptr<hittable> object) { add(object); }
  void clear() { objects.clear(); }
  void add(std::shared_ptr<hittable> object) { objects.push_back(object); }
  bool hit(const ray &r, interval range,
           hit_record &record) const override {
    hit_record temp_record;
    bool hit_anything = false;

    for (const auto &object : objects) {
      if (object->hit(r, range, temp_record)) {
        hit_anything = true;
        range.max= temp_record.t;
        record = temp_record;
      }
    }
    return hit_anything;
  }
};
