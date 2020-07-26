//
// Created by Khoa Huynh on 2020-06-29.
//

#ifndef RACETRACER_POINT_H
#define RACETRACER_POINT_H

#include "Tuple.h"
#include "Vector.h"

class Vector;
class Point : public Tuple{
public:
    Point(float x_input=0.0,float y_input=0.0,float z_input=0.0);
    Point(const Tuple &source);
    /**
     * @brief: Add operator overload
     *         could be vector+vector, point+vector,
     *         can't add 2 point (1+1) - invalid
     * @retval: Tuple
     *
     */
    Point operator+(const Vector &v) const;
    /**
     * @brief: Subtract operator overload
     *         could be point-point=vector, point-vector=point, vector-vector=vector, zero_vector-vector=vector,
     *         can't be vector-point (0-1) - invalid
     * @retval: Tuple value
     *
     */
    Vector operator-(const Point &p) const;
    Point operator-(const Vector &v) const;

};
#endif //RACETRACER_POINT_H
