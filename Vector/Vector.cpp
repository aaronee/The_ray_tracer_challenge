//
// Created by Khoa Huynh on 2020-06-29.
//

#include "Vector.h"

Vector::Vector(float x_input, float y_input, float z_input) : Tuple(x_input,y_input,z_input,0){
}
Vector::Vector(const Tuple &source) : Tuple(source.get_x(),source.get_y(),source.get_z(),0){}
Vector Vector::normalize() const{
        Vector unit_vector{};
        float magnitude = this->magnitude();
        unit_vector.value_x = this->value_x/magnitude;
        unit_vector.value_y = this->value_y/magnitude;
        unit_vector.value_z = this->value_z/magnitude;
        return unit_vector;
}

float Vector::magnitude() const {
    float magnitude{0};
    magnitude += pow(value_x, 2);
    magnitude += pow(value_y, 2);
    magnitude += pow(value_z, 2);
    magnitude = sqrt(magnitude);
    return magnitude;
}

float Vector::dot(const Vector &vector) const {
        float dot_product = (this->value_x)*(vector.value_x)+(this->value_y)*(vector.value_y)+(this->value_z)*(vector.value_z);
        return dot_product;
}

Vector Vector::cross(const Vector &vector) const {
        Vector cross_product{};
        cross_product.value_x = (this->value_y*vector.value_z) - (this->value_z*vector.value_y);
        cross_product.value_y = (this->value_z*vector.value_x) - (this->value_x*vector.value_z);
        cross_product.value_z = (this->value_x*vector.value_y) - (this->value_y*vector.value_x);
        return cross_product;
}

Vector Vector::operator-() const {
        Vector negating_vector{-(this->value_x),-(this->value_y),-(this->value_z)};
        return negating_vector;
}

Vector Vector::operator-(const Vector &t) const {
    Vector ret_vector{(this->value_x)-(t.value_x),(this->value_y)-(t.value_y),(this->value_z)-(t.value_z)};
    return ret_vector;
}

Point Vector::operator+(const Point &p) const {
    Point ret_point{(this->value_x)+(p.get_x()), (this->value_y) + (p.get_y()), (this->value_z) + (p.get_z())};
    return ret_point;
}
Vector Vector::operator+(const Vector &t) const {
    Vector ret_vector{(this->value_x)+((t.get_x())),(this->value_y)+(t.get_y()),(this->value_z)+(t.get_z())};
    return ret_vector;
}

Vector Vector::operator*(float mul_val) const {
        Vector mul_vector{(this->value_x) * mul_val, (this->value_y) * mul_val, (this->value_z) * mul_val};
        return mul_vector;
}

Vector Vector::operator/(float div_val) const {
        Vector div_vector{(this->value_x) / div_val, (this->value_y) / div_val, (this->value_z) / div_val};
        return div_vector;
}
Vector vector_refect(Vector v_in, Vector v_normal){
    return v_in - v_normal * (2*v_normal.dot(v_in));
}