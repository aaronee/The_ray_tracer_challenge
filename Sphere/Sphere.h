//
// Created by Khoa Huynh on 2020-07-12.
//

#ifndef RACETRACER_SPHERE_H
#define RACETRACER_SPHERE_H
#include "Ray.h"
#include "Material.h"

class Ray;
class Material;

class Sphere {
private:
    static uint32_t total_id;
    uint32_t obj_id;
    Material obj_material;
public:
    float transform[4][4];
    Sphere();
    uint32_t get_id(void);
    void set_translate(float matrix[3]);
    void set_scale(float matrix[3]);
    void set_rotate(float rotate_val, char axis);
    void set_shear(float xy = 0, float xz = 0, float yx = 0, float yz = 0, float zx = 0, float zy = 0);
    void set_material(Material m);
    Material get_material(void);
};

Vector sphere_normal_at(Sphere obj, Point p);


#endif //RACETRACER_SPHERE_H
