//
// Created by Yeste Lila on 2019-11-23.
//

#include "myfloat.h"
#include "ft_ptintf.h"

/*int32_t	ft_log10(uint64_t mant_val, int32_t exp_val)
{
	double	log2;

	//uint32_t mant_high = ft_64log2(mant_val);
	log2 = ((int32_t)ft_64log2(mant_val) + (exp_val - 52)) * LOG10_2 - 0.69;
	*//*if (log2 > 0)
		return (ft_ceil(log2));
	else
		return (ft_floor(log2));*//*
	//return (ft_ceil(log2));
	return (ft_round(log2));
}*/

double	ft_log10(double num)
{
	/*if (num < 1.0)
		return (ft_floor(ft_log2(num) * LOG10_2 - 0.69));*/
	num = (num < 0) ? -num : num;
	return (ft_log2(num) * LOG10_2);
}

int32_t	ft_llog10(uint64_t mant_val, int32_t exp_val)
{
	return (ft_roundl(((int32_t)ft_64log2(mant_val) + (exp_val - 63)) * LOG10_2 - 0.69));
}
