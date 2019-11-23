//
// Created by da.filiptsev on 20.11.2019.
//

#include "ft_ptintf.h"

struct	s_comp
{
	int32_t		exp_val;
	uint64_t	mant;
};

/// Если округлять типа -0.5 должно вывестись -0
double	ft_ceil(double num)
{
	uint64_t		intg;
	uint64_t		int_res;
	struct s_comp	comp;
	int32_t			shifted_exp;
	double			res;

	ft_memcpy(&intg, &num, sizeof(double));
	if ((comp.exp_val = (intg >> 52 & 0x7FF) - 1023) < 0)
		return (num > 0);
	if ((shifted_exp = 52 - comp.exp_val) <= 0)
		return (num);
	comp.mant = (intg & (1LL << 52) - 1) | 1LL << 52;
	res = (double)(comp.mant >> shifted_exp);
	if (num < 0)
		res *= -1;
	ft_memcpy(&int_res, &res, sizeof(double));
	if (res > 0 && int_res != intg)
		return  (++res);
	return (res);
}

long double	ft_ceill(long double num)
{
	uint64_t		*intg;
	uint64_t		*res_in;
	struct s_comp	comp;
	int32_t			shifted_exp;
	long double		res;

	intg = (uint64_t *)&num;
	if ((comp.exp_val = (*(intg + 1) & 0x7FFF) - 16383) < 0)
		return (num > 0);
	if ((shifted_exp = 63 - comp.exp_val) <= 0)
		return (num);
	comp.mant = *intg & 0xFFFFFFFFFFFFFFFF;
	res = (long double)(comp.mant >> shifted_exp);
	if (num < 0)
		res *= -1;
	res_in = (uint64_t *)&res;
	if (res > 0 && (*res_in != *intg || *(res_in + 1) != *(intg + 1)))
		return  (++res);
	return (res);
}
