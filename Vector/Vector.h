//
// Created by Khoa Huynh on 2020-06-29.
//

#ifndef RACETRACER_VECTOR_H
#define RACETRACER_VECTOR_H

#include "Tuple.h"
#include "Point.h"
#include "math.h"

class Point;
class Vector : public Tuple{
public:
    Vector(float x_input=0.0,float y_input=0.0,float z_input=0.0);
    Vector(const Tuple &source);
    /**
     * @brief: normalize vector -> unit vector (vector has magnitude 1)
     * @retval: Tuple
     */
    Vector normalize() const ;
    /**
     * @brief: find the magnitude of vector
     * @retval: float
     */
    float magnitude() const ;
        /**
     * @brief: calculate the dot product to the input vector
     * @retval: float
     */
    float dot(const Vector &vector) const;
    /**
     * @brief: calculate the cross product to the input vector
     * @retval: Tuple-vector
     */
    Vector cross(const Vector &vector) const;
    /**
     * @brief: unary operator overload
     *          Negating a vector and find it reverse/opposit vector, take the zero_vector subtract it to find value
     * @retval: Tuple
     *
     */
    Vector operator-(void) const;
    /**
     * @brief: Subtract operator overload
     *         could be point-point=vector, point-vector=point, vector-vector=vector, zero_vector-vector=vector,
     *         can't be vector-point (0-1) - invalid
     * @retval: Tuple value
     *
     */
     Vector operator-(const Vector &v) const ;
    /**
     * @brief: Add operator overload
     *         could be vector+vector, point+vector,
     *         can't add 2 point (1+1) - invalid
     * @retval: Tuple
     *
     */
     Vector operator+(const Vector &t) const ;
     Point operator+(const Point &p) const;
    /**
     * @brief: multiplication operator overload
     * @retval: Tuple value
     *
     */
     Vector operator*(float mul_val) const;
    /**
     * @brief: division operator overload
     * @retval: Tuple value
     *
     */
     Vector operator/(float div_val) const;
};

Vector vector_refect(Vector v_in, Vector v_normal);

#endif //RACETRACER_VECTOR_H
