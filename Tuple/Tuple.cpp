#include "Tuple.h"
#include "math.h"

Tuple::Tuple(float x_input, float y_input, float z_input, float type_input) : value_x{x_input}, value_y{y_input},value_z{z_input},value_w{type_input} {}
Tuple::Tuple(const Tuple &source) : value_x{source.value_x},value_y{source.value_y},value_z{source.value_z},value_w{source.value_w}{}
Tuple::Tuple(Tuple &&source)      : value_x{source.value_x},value_y{source.value_y},value_z{source.value_z},value_w{source.value_w}{}

bool Tuple::is_point() const {return value_w;};
bool Tuple::is_vector() const  {return (!value_w);}
void Tuple::set_x(float x_input) { value_x = x_input;};
void Tuple::set_y(float y_input) { value_y = y_input;};
void Tuple::set_z(float z_input) { value_z = z_input;};
float Tuple::get_x() const {return value_x;};
float Tuple::get_y() const {return value_y;};
float Tuple::get_z() const {return value_z;};
float Tuple::get_w() const {return value_w;};


Tuple& Tuple::operator=(const Tuple &rhs_tuple){
    if(this == &rhs_tuple){
        return *this;
    }
    this->value_x = rhs_tuple.value_x;
    this->value_y = rhs_tuple.value_y;
    this->value_z = rhs_tuple.value_z;
    this->value_w = rhs_tuple.value_w;
    return *this;
}

Tuple& Tuple::operator=(Tuple &&rhs_tuple) {
    if(this == &rhs_tuple){
        return *this;
    }
    this->value_x = rhs_tuple.value_x;
    this->value_y = rhs_tuple.value_y;
    this->value_z = rhs_tuple.value_z;
    this->value_w = rhs_tuple.value_w;
    return *this;
}

bool Tuple::operator==(const Tuple &rhs_tuple) const {
    if (this->value_x == rhs_tuple.value_x && this->value_y == rhs_tuple.value_y && this->value_z == rhs_tuple.value_z && this->value_w == rhs_tuple.value_w)
        return 1;
    else
        return 0;
}

Tuple Tuple::operator+(const Tuple t) const {
    Tuple ret_tuple{this->value_x +t.value_x, this->value_y+t.value_y, this->value_z+t.value_z, this->value_w+t.value_w};
    return ret_tuple;
}

Tuple Tuple::operator-(const Tuple t) const {
    Tuple ret_tuple{this->value_x -t.value_x, this->value_y-t.value_y, this->value_z-t.value_z, this->value_w-t.value_w};
    return ret_tuple;
}

Tuple Tuple::operator*(float mul_val) const {
    Tuple ret_tuple{this->value_x*mul_val, this->value_y*mul_val, this->value_z*mul_val, this->value_w*mul_val};
    return ret_tuple;
}
Tuple Tuple::operator/(float div_val) const {
    Tuple ret_tuple{this->value_x/div_val, this->value_y/div_val, this->value_z/div_val, this->value_w/div_val};
    return ret_tuple;
}