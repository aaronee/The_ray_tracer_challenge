//
// Created by Khoa Huynh on 2020-07-09.
//

#include "Matrix.h"
float id_matrix[4][4]{
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
};
bool matrix_compare(float matrix1[][4], float matrix2[][4]){
    for (int i = 0; i < 4 ; ++i) {
        for (int j = 0; j < 4 ; ++j) {
            if (matrix1[i][j] != matrix2[i][j]){
                return 0;
            }
        }
    }
    return 1;
}
bool matrix_compare(float matrix1[][3], float matrix2[][3]){
    for (int i = 0; i < 3 ; ++i) {
        for (int j = 0; j < 3 ; ++j) {
            if (matrix1[i][j] != matrix2[i][j]){
                return 0;
            }
        }
    }
    return 1;
}
bool matrix_compare(float matrix1[][2], float matrix2[][2]){
    for (int i = 0; i < 2 ; ++i) {
        for (int j = 0; j < 2 ; ++j) {
            if (matrix1[i][j] != matrix2[i][j]){
                return 0;
            }
        }
    }
    return 1;
}

void matrix_mul(float matrix1[][4], float matrix2[][4],float matrix_buff[][4]){
    for (int i = 0; i < 4 ; ++i) {
        for (int j = 0; j < 4 ; ++j) {
            matrix_buff[i][j] = matrix1[i][0]*matrix2[0][j]+matrix1[i][1]*matrix2[1][j]+matrix1[i][2]*matrix2[2][j]+matrix1[i][3]*matrix2[3][j];
        }
    }
}
Tuple matrix_mul(float matrix[][4], Tuple t){
    float ret[4]{};
    for (int i = 0; i <4 ; ++i) {
        ret[i] =  matrix[i][0]*t.get_x()+matrix[i][1]*t.get_y()+matrix[i][2]*t.get_z()+matrix[i][3]*t.get_w();
    }
    Tuple ret_tuple{ret[0],ret[1],ret[2],ret[3]};
    return ret_tuple;
}
void matrix_transpose(float matrix_in[][4], float matrix_buff[][4]){
    for (int i = 0; i < 4 ; ++i) {
        for (int j = 0; j < 4 ; ++j) {
            matrix_buff[j][i] = matrix_in[i][j];
        }
    }
}
void matrix_sub(float matrix_in[][4],int row, int col,float matrix_buff[][3]){
    for (int i = 0, k=0; i < 3; ++i,++k) {
        if (i==row)
            ++k;
        for (int j = 0,d=0; j < 3; ++j,++d) {
            if(j==col)
                ++d;
            matrix_buff[i][j] = matrix_in[k][d];
        }
    }
}
void matrix_sub(float matrix_in[][3],int row, int col,float matrix_buff[][2]){
    for (int i = 0, k=0; i < 2; ++i,++k) {
        if (i==row)
            ++k;
        for (int j = 0,d=0; j < 2; ++j,++d) {
            if(j==col)
                ++d;
            matrix_buff[i][j] = matrix_in[k][d];
        }
    }
}
float matrix_determine(float matrix_in[][2]){
    return matrix_in[0][0]*matrix_in[1][1]-matrix_in[0][1]*matrix_in[1][0];
}
float matrix_determine(float matrix_in[][3]){
    float matrix_buff[2][2]{};
    float ret_val{};
    for (int i = 0; i < 3; ++i) {
        ret_val += matrix_cofactor(matrix_in,0,i) * matrix_in[0][i];
    }
    return ret_val;
}
float matrix_determine(float matrix_in[][4]){
    float matrix_buff[3][3]{};
    float ret_val{};
    for (int i = 0; i < 4; ++i) {
        ret_val += matrix_cofactor(matrix_in,0,i) * matrix_in[0][i];
    }
    return ret_val;
}

float matrix_minor(float matrix_in[][3],int row, int col){
    float matrix_buf[2][2]{};
    matrix_sub(matrix_in, row, col, matrix_buf);
    return matrix_determine(matrix_buf);
}

float matrix_cofactor(float matrix_in[][3],int row, int col){
    if((row+col)%2 == 1)
        return -matrix_minor(matrix_in,row,col);
    else
        return matrix_minor(matrix_in,row,col);
}

float matrix_cofactor(float matrix_in[][4],int row, int col){
    float matrix_buff[3][3]{};
    matrix_sub(matrix_in,row,col,matrix_buff);
    if ((row+col)%2 == 1)
        return -matrix_determine(matrix_buff);
    else
        return matrix_determine(matrix_buff);
}
void matrix_inverse(float matrix_in[][4], float matrix_buff[][4])
{
    float matrix_in_det = matrix_determine(matrix_in);
    //create matrix of cofactors,
    float cofactor_matrix[4][4]{};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cofactor_matrix[i][j] = matrix_cofactor(matrix_in,i,j);
        }
    }
    float cofactor_transpose_matrix[4][4]{};
    matrix_transpose(cofactor_matrix, cofactor_transpose_matrix);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix_buff[i][j] = cofactor_transpose_matrix[i][j]/matrix_in_det;
        }
    }
}
