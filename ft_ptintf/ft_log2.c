//
// Created by Yeste Lila on 2019-11-14.
//

#include <stdint.h>
#include "myfloat.h"
#include "libft/libft.h"

static const char	log_table256[256] = {
#define LT(n) n, n, n, n, n, n, n, n, n, n, n, n, n, n, n, n
		0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
		LT(4), LT(5), LT(5), LT(6), LT(6), LT(6), LT(6),
		LT(7), LT(7), LT(7), LT(7), LT(7), LT(7), LT(7), LT(7)
};

/*uint32_t	ft_log2(uint32_t num)
{
	uint32_t			tmp;

	if ((tmp = num >> 24))
		return (24 + log_table256[tmp]);
	if ((tmp = num >> 16))
		return (16 + log_table256[tmp]);
	if ((tmp = num >> 8))
		return (8 + log_table256[tmp]);
	return (log_table256[num]);
}*/

double	ft_log2(double num)
{
	uint64_t	*dbl;
	int32_t		exp;
	double		pow;
	double		frct;

	dbl = (uint64_t *)&num;
	exp = get_exp(dbl) - 1023;
	pow = ft_pow(2, exp);
	frct = ((num - pow) / pow);
	return (exp + frct);
}

uint32_t	ft_64log2(uint64_t num)
{
	uint32_t	tmp;

	if ((tmp = num >> 32))
		return (32 + ft_log2(tmp));
	return (ft_log2((uint32_t)num));
}