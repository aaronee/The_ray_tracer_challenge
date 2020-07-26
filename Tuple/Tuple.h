#ifndef _TUPLE_
#define _TUPLE_
#include <iostream>

class Tuple
{
protected:
	float value_x ;
	float value_y ;
	float value_z ;
	float value_w ; // type of Tuple point1 or vector0
public:
    virtual bool is_point() const;			// return the type of Tuple
	virtual bool is_vector() const;
	void set_x(float x_input);
	void set_y(float y_input);
	void set_z(float z_input);
	float get_x() const;
    float get_y() const;
    float get_z() const;
    float get_w() const;

    Tuple operator+(const Tuple t) const ;
    Tuple operator-(const Tuple t) const ;
    Tuple operator*(float mul_val) const ;
    Tuple operator/(float div_val) const ;

	Tuple(float x_input=0.0,float y_input=0.0,float z_input=0.0,float type_input=0.0);
	Tuple(const Tuple &source);
	Tuple(Tuple &&source);

    /**
     * @brief: assignment operator overload
     *          take l value as param
     * @retval: Tuple
     *
     */
    Tuple& operator=(const Tuple &rhs_tuple);
    /**
     * @brief: assignment operator overload
     *          take r value as param
     * @retval: Tuple
     *
     */
    Tuple& operator=(Tuple &&rhs_tuple);
    /**
     * @brief: equalify operator overload
     * @retval: True-False
     *
     */
    bool operator==(const Tuple &rhs_tuple) const;

};
#endif