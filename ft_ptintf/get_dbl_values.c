//
// Created by da.filiptsev on 13.11.2019.
//

#include "myfloat.h"

_Bool		get_sign(t_double *dbl)
{
	return (dbl->intg >> 51);
}

int32_t		get_exp(t_double *dbl)
{
	return (dbl->intg >> 52 & 0x7FF);
}

uint64_t	get_mantissa(t_double *dbl)
{
	return (dbl->intg & (1LL << 52) - 1);
}
