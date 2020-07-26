//
// Created by Khoa Huynh on 2020-07-12.
//

#include "Sphere.h"
uint32_t Sphere::total_id = 0;

Sphere::Sphere(){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            transform[i][j] = id_matrix[i][j];
        }
    }
    ++total_id;
    obj_id = total_id;
}

uint32_t Sphere::get_id() {return obj_id;}

void Sphere::set_translate(float *matrix) {
    float temp_matrix[4][4] {};
    matrix_translate(matrix,Tuple{},0,temp_matrix);
    float old_transform[4][4]{};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            old_transform[i][j] = transform[i][j];
        }
    }
    matrix_mul(old_transform,temp_matrix,transform);
}
void Sphere::set_scale(float *matrix) {
    float temp_matrix[4][4] {};
    matrix_scale(matrix, Tuple{},0,temp_matrix);
    float old_transform[4][4]{};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            old_transform[i][j] = transform[i][j];
        }
    }
    matrix_mul(old_transform,temp_matrix,transform);
}
void Sphere::set_rotate(float rotate_val, char axis) {
    float temp_matrix[4][4] {};
    matrix_rotation(Tuple{},rotate_val,axis,temp_matrix);
    float old_transform[4][4]{};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            old_transform[i][j] = transform[i][j];
        }
    }
    matrix_mul(old_transform,temp_matrix,transform);
}
void Sphere::set_shear(float xy, float xz, float yx, float yz, float zx, float zy) {
    float temp_matrix[4][4] {};
    matrix_shear(Tuple{},xy,xz,yx,yz,zx,zy,temp_matrix);
    float old_transform[4][4]{};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            old_transform[i][j] = transform[i][j];
        }
    }
    matrix_mul(old_transform,temp_matrix,transform);
}

void Sphere::set_material(Material m) {
    obj_material = m;
}
Material Sphere::get_material() {return obj_material;}

Vector sphere_normal_at(Sphere obj, Point p){
    float inv_transform[4][4]{};
    matrix_inverse(obj.transform,inv_transform);
    Point obj_p{matrix_mul(inv_transform,p)};
    Vector obj_normal{obj_p-Point{0,0,0}};
    float transpose_transform[4][4]{};
    matrix_transpose(inv_transform,transpose_transform);
    Vector ret_v{matrix_mul(transpose_transform, obj_normal)};
    return ret_v.normalize();
}























