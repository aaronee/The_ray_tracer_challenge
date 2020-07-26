//
// Created by Khoa Huynh on 2020-07-09.
//

#ifndef RACETRACER_MATRIX_H
#define RACETRACER_MATRIX_H
#include "Tuple.h"
#include "math.h"
class Tuple;
extern float id_matrix[][4];
bool matrix_compare(float matrix1[][4], float matrix2[][4]);
bool matrix_compare(float matrix1[][3], float matrix2[][3]);
bool matrix_compare(float matrix1[][2], float matrix2[][2]);
void matrix_mul(float matrix1[][4], float matrix2[][4],float matrix_buff[][4]);
Tuple matrix_mul(float matrix[][4], Tuple t);
void matrix_transpose(float matrix_in[][4], float matrix_buff[][4]);
void matrix_sub(float matrix_in[][4],int row, int col,float matrix_buff[][3]);
void matrix_sub(float matrix_in[][3],int row, int col,float matrix_buff[][2]);
float matrix_determine(float matrix_in[][2]);
float matrix_determine(float matrix_in[][3]);
float matrix_determine(float matrix_in[][4]);
float matrix_minor(float matrix_in[][3],int row, int col);
float matrix_cofactor(float matrix_in[][3],int row, int col);
float matrix_cofactor(float matrix_in[][4],int row, int col);
void matrix_inverse(float matrix_in[][4], float matrix_buff[][4]);


Tuple matrix_translate(float *matrix, Tuple t, bool inv = 0, float trans_matrix_buff[][4] = {});
Tuple matrix_scale(float matrix[3],Tuple t, bool inv = 0,float trans_matrix_buff[][4] = {});
Tuple matrix_rotation(Tuple t, float rotation_val, char axis, float trans_matrix_buff[][4] = {});
Tuple matrix_shear(Tuple t, float xy = 0, float xz = 0, float yx = 0, float yz = 0, float zx = 0, float zy = 0, float trans_matrix_buff[][4] = {});

#endif //RACETRACER_MATRIX_H
