//
// Created by Khoa Huynh on 2020-06-29.
//

#include "Color.h"

Color::Color(float x_val, float y_val, float z_val, float w_val) : Tuple(x_val,y_val,z_val,0){}
Color Color::operator+(const Tuple t) const {
    Color ret_col{this->value_x+t.get_x(), this->value_y+t.get_y(), this->value_z+t.get_z()};
    return ret_col;
}
Color Color::operator-(const Tuple t) const {
    Color ret_col{this->value_x-t.get_x(), this->value_y-t.get_y(), this->value_z-t.get_z()};
    return ret_col;
}
Color Color::operator*(float mul_val) const {
    Color ret_col{this->value_x * mul_val, this->value_y* mul_val, this->value_z* mul_val};
    return ret_col;
}
Color Color::operator/(float mul_val) const {
    Color ret_col{this->value_x / mul_val, this->value_y / mul_val, this->value_z / mul_val};
    return ret_col;
}
Color Color::operator*(const Color &rhs) const {
    Color ret_col{this->value_x*rhs.value_x,this->value_y*rhs.value_y, this->value_z*rhs.value_z};
    return ret_col;
}
//Color& Color::operator=(const Color &rhs_color) {
//    if(this == &rhs_color){
//        return *this;
//    }
//    this->value_x = rhs_color.value_x;
//    this->value_y = rhs_color.value_y;
//    this->value_z = rhs_color.value_z;
//    return *this;
//}