//
// Created by Yeste Lila on 2019-11-14.
//

#include "myfloat.h"

double	ft_log2(long double num)
{
	uint64_t	*dbl;
	int32_t		exp;
	long double	pow;

	dbl = (uint64_t *)&num;
	exp = get_lexp(dbl) - 16383;
	pow = ft_pow(2, exp);
	return (exp + ((num - pow) / pow));
}
