//
// Created by da.filiptsev on 13.11.2019.
//

#include "myfloat.h"

_Bool		get_sign(uint64_t *dbl)
{
	return (*dbl >> 63);
}

int32_t		get_exp(uint64_t *dbl)
{
	return (*dbl >> 52 & 0x7FF);
}

uint64_t	get_mantissa(uint64_t *dbl)
{
	return (*dbl & (1LL << 52) - 1);
}
