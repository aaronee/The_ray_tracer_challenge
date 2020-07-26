//
// Created by Khoa Huynh on 2020-07-12.
//

#include "Ray.h"
Ray::Ray(Point ori_in, Vector dir_in) : origin(ori_in),direction(dir_in){}
Point Ray::get_ori() const {return origin;}
Vector Ray::get_dir() const {return direction;}

Point Ray::position(float pos) {
    Point ret_p {origin+(direction*pos)};
    return ret_p;
}

Ray ray_transform(Ray ray_to_transform, float transform_matrix[3]){
    Point ret_ori {matrix_translate(transform_matrix,ray_to_transform.get_ori())};
    Vector ret_dir {matrix_translate(transform_matrix,ray_to_transform.get_dir())};
    return Ray(ret_ori,ret_dir);
}
Ray ray_scale(Ray ray_to_scale, float scale_matrix[3]){
    Point ret_ori {matrix_scale(scale_matrix,ray_to_scale.get_ori())};
    Vector ret_dir {matrix_scale(scale_matrix,ray_to_scale.get_dir())};
    return Ray(ret_ori,ret_dir);
}
