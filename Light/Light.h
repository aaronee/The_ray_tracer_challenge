//
// Created by Khoa Huynh on 2020-07-18.
//

#ifndef RACETRACER_LIGHT_H
#define RACETRACER_LIGHT_H
#include "Point.h"
#include "Color.h"
#include "Material.h"

class Point;
class Color;

class Light {
private:
    Color intensity;
    Point position;
public:
    Light(Point pos_val, Color inten_val);
    Color get_intensity(void);
    Point get_position(void);
};

Color light_lighting(Material m, Light l, Point p, Vector eyev, Vector normalv);

#endif //RACETRACER_LIGHT_H
