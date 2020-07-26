//
// Created by Khoa Huynh on 2020-07-12.
//

#ifndef RACETRACER_RAY_H
#define RACETRACER_RAY_H
#include "Point.h"
#include "Vector.h"
#include "Matrix.h"

class Point;
class Vector;
class Matrix;

class Ray {
private:
    Point origin;
    Vector direction;
public:
    Ray(Point ori_in, Vector dir_in);
    Point get_ori(void) const;
    Vector get_dir(void) const ;
    Point position(float pos);
};

Ray ray_transform(Ray ray_to_transform, float transform_matrix[3]);
Ray ray_scale(Ray ray_to_scale, float scale_matrix[3]);

#endif //RACETRACER_RAY_H
