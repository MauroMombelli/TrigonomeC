/*
 * vector3f.h
 *
 *  Created on: 19/mar/2015
 *      Author: mauro
 */

#ifndef MY_MATH_INCLUDE_VECTOR3F_H_
#define MY_MATH_INCLUDE_VECTOR3F_H_

#include "my_math.h"


struct Vector3f{
	float x, y, z;
};

static void copy (const struct Vector3f *toClone, struct Vector3f *clone){
	clone->x = toClone->x;
	clone->y = toClone->y;
	clone->z = toClone->z;
}

static void mult (const struct Vector3f *v, float value, struct Vector3f *result){
	result->x = v->x * value;
	result->y = v->y * value;
	result->z = v->z * value;
}

static void sub (const struct Vector3f *sx, const struct Vector3f *dx, struct Vector3f *ris){
	ris->x = sx->x - dx->x;
	ris->y = sx->y - dx->y;
	ris->z = sx->z - dx->z;
}

static float dot (const struct Vector3f *sx, const struct Vector3f *dx){
	return sx->x * dx->x + sx->y * dx->y + sx->z * sx->z;
}

static void normalize (const struct Vector3f *v, struct Vector3f *result){
	float abs_sum = fabs(v->x + v->y + v->z);
	result->x = v->x / abs_sum;
	result->y = v->y / abs_sum;
	result->z = v->z / abs_sum;
}

static const struct {
	void (* copy)(const struct Vector3f*, struct Vector3f*); /* origin, copy */
	void (* mult)(const struct Vector3f*, float value, struct Vector3f*); /* sx, value, result*/
	void (* sub)(const struct Vector3f*, const struct Vector3f*, struct Vector3f*); /* sx, dx, result */
	float (* dot)(const struct Vector3f*, const struct Vector3f*); /* result is returned! */
	void (* normalize)(const struct Vector3f*, struct Vector3f*);
} vector3f_helper = {
	copy, mult, sub, dot, normalize
};

#endif /* MY_MATH_INCLUDE_VECTOR3F_H_ */
