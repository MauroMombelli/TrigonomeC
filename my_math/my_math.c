/*
 * my_math.c
 *
 *  Created on: 10/dic/2014
 *      Author: mauro
 */

#include "my_math.h"

float invSqrt(float x) {
	return 1/sqrtf(x); /* Here we can optimize, maybe */
}
