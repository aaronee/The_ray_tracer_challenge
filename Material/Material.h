//
// Created by Khoa Huynh on 2020-07-18.
//

#ifndef RACETRACER_MATERIAL_H
#define RACETRACER_MATERIAL_H
#include "Color.h"

class Color;

class Material {
private:
    Color material_color;
    float ambient;
    float diffuse;
    float specular;
    float shininess;
public:
    Material(Color color_val = Color{1,1,1}, float ambient_val = 0.1f, float diffuse_val = 0.9f, float specular_val = 0.9f, float shininess_val = 200);
    void set_color(Color color_val);
    void set_ambient(float ambient_val);
    void set_diffuse(float diffuse_val);
    void set_specular(float specular_val);
    void set_shininess(float shininess_val);

    Color get_color(void);
    float get_ambient(void);
    float get_diffuse(void);
    float get_specular(void);
    float get_shininess(void);
};


#endif //RACETRACER_MATERIAL_H
