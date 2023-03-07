//
// Created by Daniel Pfeifer on 3/6/23.
//

#ifndef RAYTRACING_SPHERE_H
#define RAYTRACING_SPHERE_H

#include "hittable.h"
#include "vec3.h"
#include "rtweekend.h"
#include "material.h"

class sphere : public hittable {
public:
    sphere() {}
    sphere(point3 c, double r, shared_ptr<material> m) : center{c}, radius{r}, mat_ptr{m} {}

    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const override;

public:
    point3 center;
    double radius;
    shared_ptr<material> mat_ptr;
};

bool sphere::hit(const ray &r, double t_min, double t_max, hit_record &rec) const {
    vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto half_b = dot(r.direction(), oc);
    auto c = oc.length_squared() - radius * radius;
    auto discriminant = half_b * half_b -  a * c;
    if (discriminant < 0) {
        return false;
    }
    auto sqrt_d = sqrt(discriminant);

    // find the nearest root between t_min and t_max (if existing)
    auto root = (-half_b - sqrt_d) / a;
    if(root < t_min || t_max < root) {
        root = (-half_b + sqrt_d) / a;
        if(root < t_min || t_max < root) {
            return false;
        }
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    rec.mat_ptr = mat_ptr;

    return true;
}


#endif //RAYTRACING_SPHERE_H
