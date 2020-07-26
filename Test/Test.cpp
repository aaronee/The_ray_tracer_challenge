#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Tuple.h"
#include "Point.h"
#include "vector"
#include "Color.h"
#include "Canvas.h"
#include "Matrix.h"
#include "math.h"

#include "iostream"
using namespace std;
using testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test {
    public:
        Tuple obj;
        ClassDeclaration(){
//            obj;
        }
    };
}

TEST_F(ClassDeclaration, type_check){
    Vector v1{};
    ASSERT_TRUE(v1.is_vector());
    ASSERT_FALSE(v1.is_point());
    Point p1{};
    ASSERT_TRUE(p1.is_vector());
    ASSERT_FALSE(p1.is_point());
    Tuple t1 {2,3,4,0};
    ASSERT_TRUE(t1.is_vector());
}

TEST_F(ClassDeclaration, add_p_v){
    Point p1 {3,-2,5};
    Vector v1 {-2,3,1};
    Point t3 = p1 + v1;
    ASSERT_EQ(t3.get_x(),1);
    ASSERT_EQ(t3.get_y(),1);
    ASSERT_EQ(t3.get_z(),6);
    ASSERT_EQ(t3.is_vector(),0); //not a vector
}

TEST_F(ClassDeclaration, sub_p_p){
    Point t1 {3,2,1};
    Point t2 {5,6,7};
    Vector t3 =t1-t2;
    ASSERT_EQ(t3.get_x(),-2);
    ASSERT_EQ(t3.get_y(),-4);
    ASSERT_EQ(t3.get_z(),-6);
    ASSERT_EQ(t3.is_vector(),1); //is a vector
}

TEST_F(ClassDeclaration, sub_p_v){
    Point t1 {3,2,1}; //point
    Vector t2 {5,6,7}; //vector
    Point t3 =t1-t2;
    ASSERT_EQ(t3.get_x(),-2);
    ASSERT_EQ(t3.get_y(),-4);
    ASSERT_EQ(t3.get_z(),-6);
    ASSERT_EQ(t3.is_point(),1); //is a point
}

TEST_F(ClassDeclaration, sub_v_v){
    Vector t1 {3,2,1}; //point
    Vector t2 {5,6,7}; //vector
    Vector t3 =t1-t2;
    ASSERT_EQ(t3.get_x(),-2);
    ASSERT_EQ(t3.get_y(),-4);
    ASSERT_EQ(t3.get_z(),-6);
    ASSERT_EQ(t3.is_point(),0); //not a point, a vector
}

TEST_F(ClassDeclaration, sub_0v_v){
    Vector t1 ; //zero vector
    Vector t2 {1,-2,3}; //vector
    Vector t3 =t1-t2;
    ASSERT_EQ(t3.get_x(),-1);
    ASSERT_EQ(t3.get_y(),2);
    ASSERT_EQ(t3.get_z(),-3);
    ASSERT_EQ(t3.is_point(),0); //not a point, a vector
}

TEST_F(ClassDeclaration, negating){
    Vector t1 {3,2,1};
    Vector t3 {-t1};
    ASSERT_EQ(t3.get_x(),-3);
    ASSERT_EQ(t3.get_y(),-2);
    ASSERT_EQ(t3.get_z(),-1);
    ASSERT_EQ(t3.is_point(),0); //not a point, a vector
}

TEST_F(ClassDeclaration, mul_div){
    Vector t1 {1,-2,3,};
    Tuple t3 = t1*3.5;
    ASSERT_EQ(t3.get_x(),3.5);
    ASSERT_EQ(t3.get_y(),-7);
    ASSERT_EQ(t3.get_z(),10.5);
    ASSERT_EQ(t3.is_point(),0);

    Vector t4 = t1/2;
    ASSERT_EQ(t4.get_x(),0.5);
    ASSERT_EQ(t4.get_y(),-1);
    ASSERT_EQ(t4.get_z(),1.5);
    ASSERT_EQ(t4.is_point(),0);

}

TEST_F(ClassDeclaration, magnitude){
    Vector t1 {3,2,1};
    ASSERT_FLOAT_EQ(t1.magnitude(),sqrt(9+4+1));
}

TEST_F(ClassDeclaration, assign_operator){
    Point original{1,2,3,};
    Point clone{};
    clone = original;
    ASSERT_EQ(clone.get_x(),1);
    ASSERT_EQ(clone.get_y(),2);
    ASSERT_EQ(clone.get_z(),3);
    ASSERT_TRUE(clone.is_point());
}

TEST_F(ClassDeclaration, assign_operator_r_value){
    Tuple clone{};
    clone = Point{1,2,3};
    ASSERT_EQ(clone.get_x(),1);
    ASSERT_EQ(clone.get_y(),2);
    ASSERT_EQ(clone.get_z(),3);
    ASSERT_TRUE(clone.is_point());
}

TEST_F(ClassDeclaration, equal_operation){
    Vector original{1,2,3};
    Vector clone{1,2,3};
    ASSERT_TRUE(original==clone);
}

TEST_F(ClassDeclaration, normalization){
    Vector original{0.1,0.1,0.1};
    Vector unit_vector = original.normalize();
    ASSERT_FLOAT_EQ(unit_vector.magnitude(),1);
    ASSERT_TRUE(unit_vector.is_vector());
}

TEST_F(ClassDeclaration, dot){
    Vector d1{1,2,3};
    Vector d2{2,3,4};
    ASSERT_FLOAT_EQ(20,d1.dot(d2));
    ASSERT_FLOAT_EQ(20,d2.dot(d1));

}

TEST_F(ClassDeclaration, cross) {
    Vector d1{1, 2, 3};
    Vector d2{2, 3, 4};
    Vector d1xd2{-1, 2, -1};
    ASSERT_TRUE(d1xd2 == d1.cross(d2));
    ASSERT_TRUE(-d1xd2 == d2.cross(d1));
}

TEST_F(ClassDeclaration, cannon_ball) {
    Point proj_p{0, 1,0};
    Vector proj_v{1, 1, 0};
    Vector grav{0,-0.01,0};
    Vector wind{0,0,0};;
    Vector env_v {grav + wind};
    int vel_magnitude {10};
    proj_v = proj_v.normalize()*vel_magnitude;

    int count {0};
    do{
        proj_p = proj_p + proj_v;
        proj_v = proj_v + env_v;
//        cout << "x: " << proj_p.get_x() << " y: " << proj_p.get_y() << " z: " << proj_p.get_z() << endl;
        count++;
    }while (proj_p.get_y()>=0);

    cout << count << endl;
    ASSERT_TRUE(env_v.is_vector());
    ASSERT_TRUE(proj_p.is_point());
}

TEST_F(ClassDeclaration, color) {
    Color c1 {0.9, 0.6, 0.75};
    Color c2 {0.7, 0.1, 0.25};
    Color c3 {c1+c2};
    ASSERT_FLOAT_EQ(c3.get_x(), 1.6);
    ASSERT_FLOAT_EQ(c3.get_y(),0.7);
    ASSERT_FLOAT_EQ(c3.get_z(),1.0);
}
TEST_F(ClassDeclaration, color_minus) {
    Color c1 {0.9, 0.6, 0.75};
    Color c2 {0.7, 0.1, 0.25};
    Color c3 {c1-c2};
    ASSERT_FLOAT_EQ(c3.get_x(), 0.2);
    ASSERT_FLOAT_EQ(c3.get_y(),0.5);
    ASSERT_FLOAT_EQ(c3.get_z(),0.5);
}
TEST_F(ClassDeclaration, color_mul) {
    Color c1 {0.2, 0.3, 0.4};
    Color c3 {c1*2};
    ASSERT_FLOAT_EQ(c3.get_x(), 0.4);
    ASSERT_FLOAT_EQ(c3.get_y(),0.6);
    ASSERT_FLOAT_EQ(c3.get_z(),0.8);
}
TEST_F(ClassDeclaration, color_mul_color) {
    Color c1 {1, 0.2, 0.4};
    Color c2 {0.9, 1, 0.1};
    Color c3 {c1*c2};
    ASSERT_FLOAT_EQ(c3.get_x(), 0.9);
    ASSERT_FLOAT_EQ(c3.get_y(),0.2);
    ASSERT_FLOAT_EQ(c3.get_z(),0.04);
}
TEST_F(ClassDeclaration, canvas) {
    Canvas lcd;
    Color red {1,0,0};
    lcd.write_pixel(2,3,red);
    Color ret_pixel {lcd.get_pixel(2,3)};
    ASSERT_TRUE(ret_pixel == red);
}

TEST_F(ClassDeclaration, canvas_to_ppm) {
//    Canvas lcd;
//    Color cy {0,2.5,3};
//    Point proj_p{0, 1,0};
//    Vector proj_v{1, 1, 0};
//    Vector grav{0,-0.01,0};
//    Vector wind{0.01,0,0};;
//    Vector env_v {grav + wind};
//    int vel_magnitude {1};
//    proj_v = proj_v.normalize()*vel_magnitude;
//
//    int count {0};
//    do{
//        proj_p = proj_p + proj_v;
//        proj_v = proj_v + env_v;
//        cout << "x: " << proj_p.get_x() << " y: " << proj_p.get_y() << " z: " << proj_p.get_z() << endl;
//        lcd.write_pixel(proj_p.get_x(),240-proj_p.get_y(),cy);
//        count++;
//    }while (proj_p.get_y()>=0);
//    cout << count << endl;
//    cout << lcd.to_ppm() << endl;
}
TEST_F(ClassDeclaration, matrix_compare) {
    float matrix1[4][4] {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {13,14,15,16}
    };
    float matrix2[4][4] {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {13,14,15,16}
    };
    float matrix3[4][4] {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {13,14,15,15}
    };

    ASSERT_TRUE(matrix_compare(matrix1,matrix2));
    ASSERT_FALSE(matrix_compare(matrix1,matrix3));
}
TEST_F(ClassDeclaration, matrix_mul) {
    float matrix1[4][4] {
            {1,2,3,4},
            {5,6,7,8},
            {9,8,7,6},
            {5,4,3,2}
    };
    float matrix2[4][4] {
            {-2,1,2,3},
            {3,2,1,-1},
            {4,3,6,5},
            {1,2,7,8}
    };
    float matrix3[4][4] {
            {20,22,50,48},
            {44,54,114,108},
            {40,58,110,102},
            {16,26,46,42}
    };
    float matrix_ret[4][4]{};
    matrix_mul(matrix1,matrix2,matrix_ret);
    ASSERT_TRUE(matrix_compare(matrix_ret,matrix3));
}
TEST_F(ClassDeclaration, matrix_mul_tuple) {
    float matrix1[4][4] {
            {1,2,3,4},
            {2,4,4,2},
            {8,6,4,1},
            {0,0,0,1}
    };
    Tuple t{1,2,3,1};
    Tuple ans{18,24,33,1};
    Tuple ret = matrix_mul(matrix1,t);
    ASSERT_TRUE(ans == ret);
}
TEST_F(ClassDeclaration, idmatrix) {
    float matrix1[4][4] {
            {1,2,3,4},
            {2,4,4,2},
            {8,6,4,1},
            {0,0,0,1}
    };
    float ret[4][4]{};
    matrix_mul(matrix1,id_matrix,ret);
    ASSERT_TRUE(matrix_compare(matrix1,ret));
}
TEST_F(ClassDeclaration, matrix_transpose) {
    float matrix1[4][4] {
            {0,9,3,0},
            {9,8,0,8},
            {1,8,5,3},
            {0,0,5,8}
    };
    float matrix_ret[4][4]{};
    matrix_transpose(matrix1, matrix_ret);
    float matrix_ans[4][4]{
            {0,9,1,0},
            {9,8,8,0},
            {3,0,5,5},
            {0,8,3,8}
    };
    ASSERT_TRUE(matrix_compare(matrix_ans,matrix_ret));
}
TEST_F(ClassDeclaration, matrix_sub) {
    float matrix1[4][4] {
            {0,9,3,0},
            {9,8,0,8},
            {1,8,5,3},
            {0,0,5,8}
    };
    float matrix_ret[3][3]{};
    matrix_sub(matrix1,1,1,matrix_ret);
    float matrix_ans[3][3]{
            {0,3,0},
            {1,5,3},
            {0,5,8}
    };
    float matrix_ret2[2][2]{};
    matrix_sub(matrix_ans,0,0,matrix_ret2);
    float matrix_ans2[2][2]{
            {5,3},
            {5,8}
    };

    ASSERT_TRUE(matrix_compare(matrix_ans,matrix_ret));
    ASSERT_TRUE(matrix_compare(matrix_ans2,matrix_ret2));

}
TEST_F(ClassDeclaration, matrix_determine) {
    float matrix[2][2]{
            {1,5},
            {-3,2}
    };

    ASSERT_EQ(17, matrix_determine(matrix));
}
TEST_F(ClassDeclaration, matrix_minor) {
    float matrix[3][3]{
            {3,5,0},
            {2,-1,-7},
            {6,-1,5}
    };

    ASSERT_EQ(25, matrix_minor(matrix,1,0));
}
TEST_F(ClassDeclaration, matrix_cofactor) {
    float matrix[3][3]{
            {3,5,0},
            {2,-1,-7},
            {6,-1,5}
    };

    ASSERT_EQ(-12, matrix_minor(matrix,0,0));
    ASSERT_EQ(-12, matrix_cofactor(matrix,0,0));
    ASSERT_EQ(25, matrix_minor(matrix,1,0));
    ASSERT_EQ(-25, matrix_cofactor(matrix,1,0));

}
TEST_F(ClassDeclaration, matrix_determine_large_matrix) {
    float matrix[3][3]{
            {1,2,6},
            {-5,8,-4},
            {2,6,4}
    };

    ASSERT_EQ(56, matrix_cofactor(matrix,0,0));
    ASSERT_EQ(12, matrix_cofactor(matrix,0,1));
    ASSERT_EQ(-46, matrix_cofactor(matrix,0,2));
    ASSERT_EQ(-196,matrix_determine(matrix));

    float matrix2[4][4]{
            {-2,-8,3,5},
            {-3,1,7,3},
            {1,2,-9,6},
            {-6,7,7,-9}
    };
    ASSERT_EQ(690, matrix_cofactor(matrix2,0,0));
    ASSERT_EQ(447, matrix_cofactor(matrix2,0,1));
    ASSERT_EQ(210, matrix_cofactor(matrix2,0,2));
    ASSERT_EQ(51, matrix_cofactor(matrix2,0,3));
    ASSERT_EQ(-4071,matrix_determine(matrix2));

}
TEST_F(ClassDeclaration, invertible) {
    float matrix1[4][4]{
            {6,4,4,4},
            {5,5,7,6},
            {4,-9,3,-7},
            {9,1,7,-6}
    };
    ASSERT_EQ(-2120,matrix_determine(matrix1));
    float matrix2[4][4]{
            {-4,2,-2,-3},
            {9,6,2,6},
            {0,-5,1,-5},
            {0,0,0,0}
    };
    ASSERT_EQ(0,matrix_determine(matrix2));
}
TEST_F(ClassDeclaration, inverse) {
    float A[4][4]{
            {-5,2,6,-8},
            {1,-5,1,8},
            {7,7,-6,-7},
            {1,-3,7,4}
    };
    ASSERT_EQ(532, matrix_determine(A));
    ASSERT_EQ(-160,matrix_cofactor(A, 2, 3));
    ASSERT_EQ(105,matrix_cofactor(A, 3, 2));
    float B[4][4]{};
    matrix_inverse(A,B);
    ASSERT_FLOAT_EQ(B[3][2], -(160.0/532.0));

}
TEST_F(ClassDeclaration, translation) {
    float translation[3]{5,-3,2};
    Point p{-3,4,5};
    Point ans{2,1,7};
    Point ret_p{matrix_translate(translation, p)};
    ASSERT_TRUE(ret_p==ans);
}
TEST_F(ClassDeclaration, ins_translation) {
    float translation[3]{5,-3,2};
    Point p{-3,4,5};
    Point ans{-8,7,3};
    Point ret_p{matrix_translate(translation, p, 1)};
    ASSERT_TRUE(ret_p==ans);
}
TEST_F(ClassDeclaration, translation_vector) {
    float translation[3]{5,-3,2};
    Vector v{-3,4,5};
    Vector ret_v{matrix_translate(translation, v)};
    ASSERT_TRUE(ret_v==v);
}
TEST_F(ClassDeclaration, scale_point) {
    float translation[3]{2,3,4};
    Point p{-4, 6, 8};
    Point ans{-8,18,32};
    Point ret_p{matrix_scale(translation, p)};
    ASSERT_TRUE(ret_p == ans);
}
TEST_F(ClassDeclaration, scale_vector) {
    float translation[3]{2,3,4};
    Vector v{-4,6,8};
    Vector ans{-8,18,32};
    Vector ret_v{matrix_scale(translation, v)};
    ASSERT_TRUE(ret_v==ans);
}
TEST_F(ClassDeclaration, scale_vector_inv) {
    float translation[3]{2,3,4};
    Vector v{-4,6,8};
    Vector ans{-2,2,2};
    Vector ret_v{matrix_scale(translation, v,1)};
    ASSERT_TRUE(ret_v==ans);
}
TEST_F(ClassDeclaration, reflect_point) {
    float translation[3]{-1,1,1};
    Point p{2, 3, 4};
    Point ans{-2,3,4};
    Point ret_p{matrix_scale(translation, p, 1)};
    ASSERT_TRUE(ret_p == ans);
}
TEST_F(ClassDeclaration, x_rotate) {
    Point p{0,1,0};
    float full_quarter = 3.14/2;
    float half_quarter = 3.14/4;
    Point ret_point{matrix_rotation(p,half_quarter,'x')};
    Point ans_point{0, static_cast<float>(sqrt(2)/2),static_cast<float>(sqrt(2)/2)};
    Point ret_point2{matrix_rotation(p,full_quarter,'x')};
    Point ans_point2{0, 0,1};
}
TEST_F(ClassDeclaration, y_rotate) {
    Point p{0,0,1};
    float full_quarter = 3.14/2;
    float half_quarter = 3.14/4;
    Point ret_point{matrix_rotation(p,half_quarter,'y')};
    Point ans_point{static_cast<float>(sqrt(2)/2),0,static_cast<float>(sqrt(2)/2)};
    Point ret_point2{matrix_rotation(p,full_quarter,'y')};
    Point ans_point2{1, 0,0};
}
TEST_F(ClassDeclaration, z_rotate) {
    Point p{0,1,0};
    float full_quarter = 3.14/2;
    float half_quarter = 3.14/4;
    Point ret_point{matrix_rotation(p,half_quarter,'z')};
    Point ans_point{static_cast<float>(-sqrt(2)/2),static_cast<float>(sqrt(2)/2),0};
    Point ret_point2{matrix_rotation(p,full_quarter,'z')};
    Point ans_point2{-1, 0,0};
}
TEST_F(ClassDeclaration, matrix_shearing) {
    Point p{2,3,4};
    Point ansxy{5,3,4};
    Point ansxz{6,3,4};
    Point ret_p{matrix_shear(p,1)};
    ASSERT_TRUE(ret_p==ansxy);
    Point ret_p1{matrix_shear(p,0,1)};
    ASSERT_TRUE(ret_p1==ansxz);
    Point ansyx{2,5,4};
    Point ret_p2{matrix_shear(p,0,0,1)};
    ASSERT_TRUE(ret_p2==ansyx);
    Point ansyz{2,7,4};
    Point ret_p3{matrix_shear(p,0,0,0,1)};
    ASSERT_TRUE(ret_p3==ansyz);
    Point anszx{2,3,6};
    Point ret_p4{matrix_shear(p,0,0,0,0,1)};
    ASSERT_TRUE(ret_p4==anszx);
    Point anszy{2,3,7};
    Point ret_p5{matrix_shear(p,0,0,0,0,0,1)};
    ASSERT_TRUE(ret_p5==anszy);
}
TEST_F(ClassDeclaration, chaining_transform) {
    Point p{1,0,1};
    float matrix_t[3]{10,5,7};
    float matrix_s[3]{5,5,5};
    Point ret_p{matrix_translate(matrix_t,matrix_scale(matrix_s,matrix_rotation(p,3.14/2,'x')))};
    ASSERT_FLOAT_EQ(15, ret_p.get_x());
}
TEST_F(ClassDeclaration, clock_draw) {
//    float pi {3.1415};
//    Point clock[13]{};
//    Point origin_p{0,0,0};
//    clock[0] = origin_p;
//    Point po_12h{0,1,0};
//    clock[1]= po_12h;
//    float scale[3]{90,90,0};
//    clock[1] = matrix_scale(scale,clock[1]);
//    for (int i = 2; i < 13; ++i) {
//        clock[i] = matrix_rotation(clock[i-1],pi/6,'z');
//    }
//    for (int i = 0; i < 13; ++i) {
//        clock[i].set_x(clock[i].get_x()+120);
//        clock[i].set_y(clock[i].get_y()+120);
//    }
//
//    //draw on canvas
//    Canvas p;
//    Color ran{255,0,0};
//    for (int j = 0; j < 13; ++j) {
//        p.write_pixel(clock[j].get_x(),clock[j].get_y(),ran);
//    }
//    cout << p.to_ppm() << endl;
}





















