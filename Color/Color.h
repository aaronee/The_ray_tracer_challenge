//
// Created by Khoa Huynh on 2020-06-29.
//

#ifndef RACETRACER_COLOR_H
#define RACETRACER_COLOR_H
#include "Tuple.h"

class Color : public Tuple {
public:
    Color(float x_val=0.0, float y_val=0.0, float z_val=0.0, float w_val = 0.0);
    Color operator+(const Tuple t) const ;
    Color operator-(const Tuple t) const ;
    Color operator*(float mul_val) const ;
    Color operator/(float div_val) const ;
    Color operator*(const Color &rhs) const;
//    Color& operator=(const Color &rhs_color);
};


#endif //RACETRACER_COLOR_H
