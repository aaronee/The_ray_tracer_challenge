//
// Created by Khoa Huynh on 2020-06-29.
//

#include "Point.h"

Point::Point(float x_input, float y_input, float z_input) : Tuple(x_input,y_input,z_input,1) {}
Point::Point(const Tuple &source) : Tuple(source.get_x(),source.get_y(),source.get_z(),1){
}
Point Point::operator+(const Vector &v) const {
    Point ret_point{(this->value_x)+(v.get_x()),(this->value_y)+(v.get_y()),(this->value_z)+(v.get_z())};
    return ret_point;
}

Vector Point::operator-(const Point &p) const {
    Vector ret_vector{(this->value_x)-(p.value_x),(this->value_y)-(p.value_y),(this->value_z)-(p.value_z)};
    return ret_vector;
}

Point Point::operator-(const Vector &v) const{
    Point ret_vector{(this->value_x)-(v.get_x()),(this->value_y)-(v.get_y()),(this->value_z)-(v.get_z())};
    return ret_vector;
}

