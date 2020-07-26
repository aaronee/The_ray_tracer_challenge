//
// Created by Khoa Huynh on 2020-07-13.
//

#ifndef RACETRACER_INTERSECTION_H
#define RACETRACER_INTERSECTION_H

#include <vector>
#include "Sphere.h"
using namespace std;
class Sphere;

class Intersection {
private:
    float t;
    uint32_t obj_id;
    bool no_inter;
public:
    Intersection(float t_value = 0.0, Sphere obj = Sphere{}, bool no_inter_val = 0);
    float get_t(void) const;
    uint32_t get_obj_id(void) const;
    bool is_no_hit(void);
};

class Intersections{
private:
    vector<Intersection>t_list{};
    uint32_t hit_pos;
    bool no_hit;
public:
    Intersections(Intersection t);
    void add_intersection(Intersection t);
    float t_at(uint32_t pos);
    uint32_t id_at(uint32_t pos);
    uint32_t count(void);
    uint32_t hit(void);                     // return the position of hit in the vector
    bool is_no_hit(void);
};

Intersections sphere_intersect(Sphere s, Ray r);

#endif //RACETRACER_INTERSECTION_H
