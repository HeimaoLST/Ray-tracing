#pragma once

#include "ray.h"
#include "vec3.h"

class hit_record {
    public:
        point3 p;
        vec3 normal;
        double t;
};

class hittable {
    virtual ~hittable() = default;
    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &record) const = 0;

}
