/*
 * vector3f.h
 *
 *  Created on: 19/mar/2015
 *      Author: mauro
 */

#ifndef MY_MATH_INCLUDE_VECTOR3I16_H_
#define MY_MATH_INCLUDE_VECTOR3I16_H_

#include "my_math.h"

struct Vector3i16{
	int16_t x, y, z;
};

static void copy_i16_ (const struct Vector3i16 *toClone, struct Vector3i16 *clone){
	clone->x = toClone->x;
	clone->y = toClone->y;
	clone->z = toClone->z;
}

static void mult_i16_ (const struct Vector3i16 *v, float value, struct Vector3i16 *result){
	result->x = v->x * value;
	result->y = v->y * value;
	result->z = v->z * value;
}

static void sub_i16_ (const struct Vector3i16 *sx, const struct Vector3i16 *dx, struct Vector3i16 *ris){
	ris->x = sx->x - dx->x;
	ris->y = sx->y - dx->y;
	ris->z = sx->z - dx->z;
}

static float dot_i16_ (const struct Vector3i16 *sx, const struct Vector3i16 *dx){
	return sx->x * dx->x + sx->y * dx->y + sx->z * sx->z;
}

static void normalize_i16_ (const struct Vector3i16 *v, struct Vector3i16 *result){
	float abs_sum = fabs(v->x + v->y + v->z);
	result->x = v->x / abs_sum;
	result->y = v->y / abs_sum;
	result->z = v->z / abs_sum;
}

static const struct {
	void (* copy)(const struct Vector3i16*, struct Vector3i16*); /* origin, copy */
	void (* mult)(const struct Vector3i16*, float value, struct Vector3i16*); /* sx, value, result*/
	void (* sub)(const struct Vector3i16*, const struct Vector3i16*, struct Vector3i16*); /* sx, dx, result */
	float (* dot)(const struct Vector3i16*, const struct Vector3i16*); /* result is returned! */
	void (* normalize)(const struct Vector3i16*, struct Vector3i16*);
} vector3i16_helper = {
	copy_i16_, mult_i16_, sub_i16_, dot_i16_, normalize_i16_
};

#endif /* MY_MATH_INCLUDE_VECTOR3F_H_ */
