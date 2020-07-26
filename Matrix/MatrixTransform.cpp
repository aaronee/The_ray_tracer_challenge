//
// Created by Khoa Huynh on 2020-07-10.
//
#include "Matrix.h"

Tuple matrix_translate(float *matrix, Tuple t, bool inv, float trans_matrix_buff[][4]){
    if(inv) {
        float translation_matrix[4][4]{
                {1, 0, 0, -matrix[0]},
                {0, 1, 0, -matrix[1]},
                {0, 0, 1, -matrix[2]},
                {0, 0, 0, 1}
        };
        return matrix_mul(translation_matrix, t);
    }
        else {
        float translation_matrix[4][4]{
                {1, 0, 0, matrix[0]},
                {0, 1, 0, matrix[1]},
                {0, 0, 1, matrix[2]},
                {0, 0, 0, 1}
        };
        if(trans_matrix_buff != nullptr) {
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    trans_matrix_buff[i][j] = translation_matrix[i][j];
                }
            }
        }
        return matrix_mul(translation_matrix, t);
    }
}
Tuple matrix_scale(float matrix[3],Tuple t, bool inv, float trans_matrix_buff[][4]){
    if(inv) {
        float translation_matrix[4][4]{
                {1/matrix[0], 0, 0, 0},
                {0, 1/matrix[1], 0, 0},
                {0, 0, 1/matrix[2], 0},
                {0, 0, 0, 1}
        };
        return matrix_mul(translation_matrix, t);
    }
        else {
        float translation_matrix[4][4]{
                {matrix[0], 0, 0, 0},
                {0, matrix[1], 0, 0},
                {0, 0, matrix[2], 0},
                {0, 0, 0, 1}
        };
        if(trans_matrix_buff != nullptr) {
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    trans_matrix_buff[i][j] = translation_matrix[i][j];
                }
            }
        }
        return matrix_mul(translation_matrix, t);
    }
}
Tuple matrix_rotation(Tuple t, float rotation_val, char axis, float trans_matrix_buff[][4]){
    float rotation_matrix[4][4]{
            {1,0,0,0},
            {0,1,0,0},
            {0,0,1,0},
            {0,0,0,1}
    };
        switch (axis) {
    case 'x':
        rotation_matrix[1][1] = cos(rotation_val);
        rotation_matrix[2][1] = sin(rotation_val);
        rotation_matrix[1][2] = -sin(rotation_val);
        rotation_matrix[2][2] = cos(rotation_val);
        break;
    case 'y':
        rotation_matrix[0][0] = cos(rotation_val);
        rotation_matrix[0][2] = sin(rotation_val);
        rotation_matrix[2][0] = -sin(rotation_val);
        rotation_matrix[2][2] = cos(rotation_val);
        break;
    case 'z':
        rotation_matrix[0][0] = cos(rotation_val);
        rotation_matrix[0][1] = -sin(rotation_val);
        rotation_matrix[1][0] = sin(rotation_val);
        rotation_matrix[1][1] = cos(rotation_val);
        break;
    default:
        break;
    }
    if(trans_matrix_buff != nullptr) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                trans_matrix_buff[i][j] = rotation_matrix[i][j];
            }
        }
    }
    return Tuple{matrix_mul(rotation_matrix,t)};
}

Tuple matrix_shear(Tuple t, float xy, float xz, float yx, float yz, float zx, float zy, float trans_matrix_buff[][4])
{
    float shear_matrix[4][4]{
            {1,xy,xz,0},
            {yx,1,yz,0},
            {zx,zy,1,0},
            {0,0,0,1}
    };
    if(trans_matrix_buff != nullptr) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                trans_matrix_buff[i][j] = shear_matrix[i][j];
            }
        }
    }
    return Tuple{matrix_mul(shear_matrix,t)};
}



















