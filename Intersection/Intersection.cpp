//
// Created by Khoa Huynh on 2020-07-13.
//

#include "Intersection.h"

/**
 * Intersection
 *
 * */

Intersection::Intersection(float t_value, Sphere obj, bool no_inter_val) : t(t_value) ,obj_id{obj.get_id()}, no_inter{no_inter_val}{}
float Intersection::get_t() const {return t;}
uint32_t Intersection::get_obj_id() const {return obj_id;}
bool Intersection::is_no_hit() {return no_inter;}

/**
 * Intersections
 *
 * */

Intersections::Intersections(Intersection t) : hit_pos{0}{
    if(t.is_no_hit())
        no_hit = 1;
    else
        no_hit = 0;
    t_list.push_back(t);
}
uint32_t Intersections::count() {return t_list.size();}

void Intersections::add_intersection(Intersection t) {
    if (t.get_t() > t_list.at(t_list.size()-1).get_t())
        t_list.push_back(t);
    else {
        auto list_size{t_list.size()};
        for (auto i = 0; i < list_size; ++i) {
            if (t_list.at(i).get_t() >= t.get_t()){
                t_list.insert(t_list.begin() + i, t);
                break;
                }
        }
    }
    auto list_size = t_list.size();
    for (int i = 0; i < list_size; ++i) {
        if (t_list.at(i).get_t() >= 0) {
            hit_pos = i;
            break;
        }
    }
}

float Intersections::t_at(uint32_t pos) {
    return t_list.at(pos).get_t();
}

uint32_t Intersections::id_at(uint32_t pos) {
    return t_list.at(pos).get_obj_id();
}
uint32_t Intersections::hit() {return hit_pos;}
bool Intersections::is_no_hit() {return no_hit;}

Intersections sphere_intersect(Sphere s, Ray r){
    float inv_transform[4][4]{};
    matrix_inverse(s.transform,inv_transform);
    Point new_p{matrix_mul(inv_transform,r.get_ori())};
    Vector new_v{matrix_mul(inv_transform,r.get_dir())};
    Ray new_r{new_p,new_v};

    Vector sphere_to_ray{new_p-Point{}};
    float a = new_r.get_dir().dot(new_r.get_dir());
    float b = 2*(new_r.get_dir().dot(sphere_to_ray));
    float c = sphere_to_ray.dot(sphere_to_ray) - 1;
    float discriminant = b*b-4*a*c;
    if (discriminant < 0)
        return Intersections{Intersection{0,Sphere{},1}};
    else {
        float sqrt_discriminant = sqrt(discriminant);
        float t1 = (-b - sqrt_discriminant) / (2 * a);
        float t2 = (-b + sqrt_discriminant) / (2 * a);
        Intersection a{t1,s};
        Intersection b{t2,s};
        Intersections xs{a};
        xs.add_intersection(b);
        return xs;
    }
}