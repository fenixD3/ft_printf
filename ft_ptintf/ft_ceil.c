//
// Created by da.filiptsev on 20.11.2019.
//

#include "ft_ptintf.h"

double	ft_ceil(double num)
{
	uint64_t	intg;
	int32_t		exp;
	uint64_t	mant;

	ft_memcpy(&intg, &num, sizeof(double));
	exp = (intg >> 52 & 0x7FF) - 1023;
	if (exp < 0)
		return num > 0;
	mant = (intg & (1LL << 52) - 1) | 1LL << 52;
}