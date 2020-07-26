#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Canvas.h"
#include "Color.h"
#include "Point.h"
#include "Matrix.h"
#include "Sphere.h"
#include "Intersection.h"
#include "Vector.h"
#include "Ray.h"
#include "Light.h"

#include "iostream"
using namespace std;

int main(int argc, char* argv[])
{
    Point r_ori {0,0,-5};
    Sphere s{};
    Material m{Color{0,1,1}};
    s.set_material(m);
    Light light_source{Point{10,5,-10},Color{1,1,1}};


    float wall_z = 10.0f;
    float wall_size = 7.0f;
    float pixel_size = wall_size/240;
    float half = wall_size/2;

    Canvas c{};
    Color red{255,0,0};
    for (int y = 0; y < 240 ; ++y) {
       float world_y = half - pixel_size*y;
        for (int x = 0; x < 240; ++x) {
            float world_x = -half+pixel_size*x;
            Point position{world_x,world_y,wall_z};
            Vector origin_to_wall {position-r_ori};
            Ray r{r_ori,origin_to_wall.normalize()};
            Intersections xs {sphere_intersect(s,r)};
            if(!xs.is_no_hit()){
                Point p {r.position(xs.t_at(xs.hit()))};
                Vector normalv{sphere_normal_at(s,p)};
                Vector eyev{-r.get_dir()};
                Color color_at_point{light_lighting(s.get_material(),light_source,p,eyev,normalv)};
                c.write_pixel(x,y,color_at_point);
            }
        }
    }

    cout << c.to_ppm() << endl;

    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

