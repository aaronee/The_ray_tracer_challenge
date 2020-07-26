//
// Created by Khoa Huynh on 2020-07-12.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Tuple.h"
#include "Point.h"
#include "Color.h"
#include "Canvas.h"
#include "Matrix.h"
#include "math.h"
#include "Ray.h"
#include "Sphere.h"
#include "Intersection.h"
#include "Light.h"
#include "Material.h"

#include "iostream"
using namespace std;
using testing::Eq;

TEST(ray, type_check){
    Point p{1,2,3};
    Vector v{4,5,6};
    Ray r{p,v};
    ASSERT_TRUE(r.get_ori() == p);
    ASSERT_TRUE(r.get_dir() == v);
}
TEST(ray, position){
    Ray r{Point{2,3,4},Vector{1,0,0}};
    Point ret_p{r.position(0)};
    Point ans{2,3,4};
    ASSERT_TRUE(ret_p == ans);
    Point ret_p2{r.position(1)};
    Point ans2{3,3,4};
    ASSERT_TRUE(ret_p2 == ans2);
    Point ret_p3{r.position(-1)};
    Point ans3{1,3,4};
    ASSERT_TRUE(ret_p3 == ans3);
    Point ret_p4{r.position(2.5)};
    Point ans4{4.5,3,4};
    ASSERT_TRUE(ret_p4 == ans4);
}
TEST(ray, intersection){
    uint8_t count{};
    float intersections[2]{};
    Ray r{Point{0,1,-5},Vector{0,0,1}};
    Ray r2{Point{0,2,-5},Vector{0,0,1}};
    Ray r3{Point{0,0,0},Vector{0,0,1}};
    Ray r4{Point{0,0,5},Vector{0,0,1}};

    Sphere s{};
    Intersections xs {sphere_intersect(s,r)};
    ASSERT_EQ(2,xs.count());
    ASSERT_FLOAT_EQ(5.0, xs.t_at(0));
    ASSERT_FLOAT_EQ(5.0, xs.t_at(1));

    Intersections xs1 {sphere_intersect(s,r2)};
    ASSERT_EQ(0,count);

    Intersections xs2 {sphere_intersect(s,r3)};
    ASSERT_EQ(2,xs.count());
    ASSERT_FLOAT_EQ(-1.0, xs2.t_at(0));
    ASSERT_FLOAT_EQ(1.0, xs2.t_at(1));

    Intersections xs3 {sphere_intersect(s,r4)};
    ASSERT_EQ(2,xs3.count());
    ASSERT_FLOAT_EQ(-6.0, xs3.t_at(0));
    ASSERT_FLOAT_EQ(-4.0, xs3.t_at(1));
}
TEST(Intersection, class_test){
    Sphere s{};
    Sphere s1{};
    Intersection i{3.5,s};
    Intersection i1{3,s1};
    ASSERT_EQ(i.get_obj_id(), s.get_id());
    ASSERT_EQ(i.get_t(),3.5);

    ASSERT_EQ(i1.get_obj_id(), s1.get_id());
    ASSERT_NE(i1.get_obj_id(),s.get_id());
}
TEST(Intersection, intersections){
    Sphere s{};
    Intersection i1{1,s};
    Intersection i2{2,s};
    vector<Intersection>list{i1,i2};
    ASSERT_EQ(list.size(),2);
    ASSERT_EQ(list.at(0).get_t(),1);
    ASSERT_EQ(list.at(1).get_t(),2);
}
TEST(Intersection, hit){
    Sphere s{};
    Intersection i1{5,s};
    Intersection i2{7,s};
    Intersection i3{-3,s};
    Intersection i4{2,s};

    Intersections list{i1};
    list.add_intersection(i2);
    list.add_intersection(i3);
    list.add_intersection(i4);

    ASSERT_EQ(list.count(),4);
    ASSERT_EQ(list.t_at(0),-3);
    ASSERT_EQ(list.t_at(1),2);
    ASSERT_EQ(list.t_at(2),5);
    ASSERT_EQ(list.t_at(3),7);


    ASSERT_FLOAT_EQ(i4.get_t(), list.t_at(list.hit()));
}

TEST(ray, translate){
    Point p1{1,2,3};
    Vector v1{0,1,0};
    Ray r1{p1,v1};
    float translation_maxtrix[3]{3,4,5};
    Ray r2 {ray_transform(r1,translation_maxtrix)};
    Point p2{4,6,8};
    Vector v2{0,1,0};
    ASSERT_TRUE(r2.get_ori()==p2);
    ASSERT_TRUE(r2.get_dir()==v2);
}
TEST(ray, scale){
    Point p1{1,2,3};
    Vector v1{0,1,0};
    Ray r1{p1,v1};
    float scale_matrix[3]{2, 3, 4};
    Ray r2 {ray_scale(r1, scale_matrix)};
    Point p2{2,6,12};
    Vector v2{0,3,0};
    ASSERT_TRUE(r2.get_ori()==p2);
    ASSERT_TRUE(r2.get_dir()==v2);
}
TEST(ray, add_transform_to_sphere){
    Sphere s{};
    float trans_matrix[3]{2,3,4};
    s.set_translate(trans_matrix);
    ASSERT_EQ(-trans_matrix[0], s.transform[0][3]);
    ASSERT_EQ(-trans_matrix[1], s.transform[1][3]);
    ASSERT_EQ(-trans_matrix[2], s.transform[2][3]);

}
TEST(ray, intersections_from_transformed_sphere){
    Sphere s{};
    Ray r{Point{0,0,-5},Vector{0,0,1}};
    float scale_matrix[3]{2,2,2};
    s.set_scale(scale_matrix);
    Intersections xs{sphere_intersect(s,r)};
    ASSERT_TRUE(xs.count()==2);
    ASSERT_EQ(xs.t_at(0),3);
    ASSERT_EQ(xs.t_at(1),7);

}
TEST(ray, intersections_from_transformed_sphere2){
    Sphere s{};
    Ray r{Point{0,0,-5},Vector{0,0,1}};
    float translation_matrix[3]{5,0,0};
    s.set_translate(translation_matrix);
    Intersections xs{sphere_intersect(s,r)};

    ASSERT_TRUE(xs.is_no_hit());
}
TEST(sphere_feature,normalize_at){
    Sphere s{};
    Vector ans{0,1,0};
    Vector nv{sphere_normal_at(s,Point{0,1,0})};
    ASSERT_TRUE(nv == ans);
    float sqrt_3 = sqrt(3);
    Vector nv2 {sphere_normal_at(s, Point{sqrt_3/3,sqrt_3/3,sqrt_3/3})};
    Vector nv2_normalize{nv2.normalize()};
    ASSERT_FLOAT_EQ(nv2.get_x(),nv2_normalize.get_x());
    ASSERT_FLOAT_EQ(nv2.get_y(),nv2_normalize.get_y());
    ASSERT_FLOAT_EQ(nv2.get_z(),nv2_normalize.get_z());
}
TEST(sphere_feature,normalize_at_translated_sphere){
    Sphere s{};
    float translate_matrix[3]{0,1,0};
    s.set_translate(translate_matrix);
    Vector normal_vector{sphere_normal_at(s,Point{0,1.70711,-0.70711})};
    ASSERT_FLOAT_EQ(normal_vector.get_x(),0);
    ASSERT_FLOAT_EQ(normal_vector.get_y(),0.7071068);
    ASSERT_FLOAT_EQ(normal_vector.get_z(),-0.7071068);
}
TEST(sphere_feature,normalize_at_translated_sphere_2){
    Sphere s{};
    float pi =3.14159f;
    float scale_matrix[3]{1,0.5,1};

    s.set_scale(scale_matrix);
    s.set_rotate(pi/5, 'z');

    float sqrt_2 = sqrt(2.0f)/2.0f;
    Point p{0,sqrt_2,-sqrt_2};
    Vector normal_vector{sphere_normal_at(s,p)};
    ASSERT_FLOAT_EQ(normal_vector.get_x(),0);
    ASSERT_FLOAT_EQ(normal_vector.get_y(),0.9701425f);
    ASSERT_FLOAT_EQ(normal_vector.get_z(),-0.24253565f);
}
TEST(sphere_feature,Put_together){
//    Point r_ori {0,0,-5};
//    Sphere s{};
//    float pi{3.14159f};
//
//    float scale_matrix1[3]{0.5,0.5,0.5};
//    float scale_matrix2[3]{1,0.5,1};
//    s.set_scale(scale_matrix1);
//    s.set_scale(scale_matrix2);
//    s.set_rotate(pi/5,'z');
//    float wall_z = 10.0f;
//    float wall_size = 7.0f;
//    float pixel_size = wall_size/240;
//    float half = wall_size/2;
//
//    Canvas c{};
//    Color red{1,0,0};
//    for (int y = 0; y < 240 ; ++y) {
//        float world_y = half - pixel_size*y;
//        for (int x = 0; x < 240; ++x) {
//            float world_x = -half+pixel_size*x;
//            Point position{world_x,world_y,wall_z};
//            Vector origin_to_wall {position-r_ori};
//            Ray r{r_ori,origin_to_wall.normalize()};
//            Intersections xs {sphere_intersect(s,r)};
//            if(!xs.is_no_hit())
//                c.write_pixel(x,y,red);
//        }
//    }
//
//    cout << c.to_ppm() << endl;
}

TEST(Vector, reflect){
    Vector v{1,-1,0};
    Vector n{0,1,0};
    Vector r{vector_refect(v,n)};
    Vector ans{1,1,0};
    ASSERT_TRUE(r == ans);
}
TEST(Vector, reflect2){
    float sqrt_2 = sqrt(2);
    Vector v{0,-1,0};
    Vector n{sqrt_2/2,sqrt_2/2,0};
    Vector r{vector_refect(v,n)};
    Vector ans{1,0,0};
    ASSERT_FLOAT_EQ(r.get_x(),ans.get_x());
}
TEST(light, class_test){
    Color intensity{1,1,1};
    Point position{0,0,0};
    Light light_source(position,intensity);
    ASSERT_TRUE(light_source.get_position() == position);
    ASSERT_TRUE(light_source.get_intensity() == intensity);
}
TEST(material, class_test){
    Material m{};
    m.set_ambient(1);
    Sphere s{};
    s.set_material(m);
    Material ret_material{s.get_material()};
    ASSERT_TRUE(ret_material.get_color() == m.get_color());
    ASSERT_FLOAT_EQ(ret_material.get_ambient(),1);
}
TEST(material, eye_light){
    Material m{};
    Point position{0,0,0};
    Vector eyev{0,0,-1};
    Vector normalv{0,0,-1};
    Light lightx{Point{0,0,-10},Color{1,1,1}};
    Color ret_color{light_lighting(m,lightx,position,eyev,normalv)};
    Color ans{1.9,1.9,1.9};

    ASSERT_FLOAT_EQ(ret_color.get_x(), ans.get_x());
    ASSERT_FLOAT_EQ(ret_color.get_y(), ans.get_y());
    ASSERT_FLOAT_EQ(ret_color.get_z(), ans.get_z());

}
TEST(material, eye_light2){
    Material m{};
    Point position{0,0,0};
    float sqr_val = sqrt(2)/2;
    Vector eyev{0,sqr_val,-sqr_val};
    Vector normalv{0,0,-1};
    Light lightx{Point{0,0,-10},Color{1,1,1}};
    Color ret_color{light_lighting(m,lightx,position,eyev,normalv)};
    Color ans{1,1,1};

    ASSERT_FLOAT_EQ(ret_color.get_x(), ans.get_x());
    ASSERT_FLOAT_EQ(ret_color.get_y(), ans.get_y());
    ASSERT_FLOAT_EQ(ret_color.get_z(), ans.get_z());
}
TEST(material, eye_light3){
    Material m{};
    Point position{0,0,0};
    Vector eyev{0,0,-1};
    Vector normalv{0,0,-1};
    Light lightx{Point{0,10,-10},Color{1,1,1}};
    Color ret_color{light_lighting(m,lightx,position,eyev,normalv)};
    Color ans{0.73639607,0.73639607,0.73639607};

    ASSERT_FLOAT_EQ(ret_color.get_x(), ans.get_x());
    ASSERT_FLOAT_EQ(ret_color.get_y(), ans.get_y());
    ASSERT_FLOAT_EQ(ret_color.get_z(), ans.get_z());
}
TEST(material, eye_light4){
    Material m{};
    Point position{0,0,0};
    float sqr_val = sqrt(2)/2;
    Vector eyev{0,-sqr_val,-sqr_val};
    Vector normalv{0,0,-1};
    Light lightx{Point{0,10,-10},Color{1,1,1}};
    Color ret_color{light_lighting(m,lightx,position,eyev,normalv)};
    Color ans{1.6363853,1.6363853,1.6363853};

    ASSERT_FLOAT_EQ(ret_color.get_x(), ans.get_x());
    ASSERT_FLOAT_EQ(ret_color.get_y(), ans.get_y());
    ASSERT_FLOAT_EQ(ret_color.get_z(), ans.get_z());
}
TEST(material, eye_light5){
    Material m{};
    Point position{0,0,0};
    Vector eyev{0,0,-1};
    Vector normalv{0,0,-1};
    Light lightx{Point{0,0,10},Color{1,1,1}};
    Color ret_color{light_lighting(m,lightx,position,eyev,normalv)};
    Color ans{0.1,0.1,0.1};

    ASSERT_FLOAT_EQ(ret_color.get_x(), ans.get_x());
    ASSERT_FLOAT_EQ(ret_color.get_y(), ans.get_y());
    ASSERT_FLOAT_EQ(ret_color.get_z(), ans.get_z());
}








