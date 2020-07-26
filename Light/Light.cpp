//
// Created by Khoa Huynh on 2020-07-18.
//

#include "Light.h"
Light::Light(Point pos_val, Color inten_val) : position(pos_val), intensity(inten_val){}
Color Light::get_intensity() {return intensity;}
Point Light::get_position() {return position;}

Color light_lighting(Material m, Light l, Point p, Vector eyev, Vector normalv){
    Color effective_color{m.get_color()*l.get_intensity()};
    Vector lightv{(l.get_position()-p).normalize()};
    Color ambient_color {effective_color*m.get_ambient()};
    float light_dot_normal {lightv.dot(normalv)};
    if (light_dot_normal < 0)
    {
        Color diffuse_color{};
        Color specular_color{};
        return ambient_color+diffuse_color+specular_color;
    } else{
        Color diffuse_color{effective_color*(m.get_diffuse()*light_dot_normal)};
        Vector reflecttv{vector_refect(-lightv,normalv)};
        float reflect_dot_eye{reflecttv.dot(eyev)};
        if (reflect_dot_eye < 0)
        {
            Color specular_color{};
            return ambient_color+diffuse_color+specular_color;
        }else{
            float factor = pow(reflect_dot_eye,m.get_shininess());
            Color specular_color{l.get_intensity()*m.get_specular()*factor};
            return ambient_color+diffuse_color+specular_color;
        }
    }
}