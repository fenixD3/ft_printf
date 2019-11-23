//
// Created by Yeste Lila on 2019-11-23.
//

#include "myfloat.h"
#include "ft_ptintf.h"

int32_t	ft_log10(uint64_t mant_val, int32_t exp_val)
{
	return (ft_ceil(((int32_t)ft_64log2(mant_val) + (exp_val - 52)) * LOG10_2 - 0.69));
}

int32_t	ft_llog10(uint64_t mant_val, int32_t exp_val)
{
	return (ft_ceill(((int32_t)ft_64log2(mant_val) + (exp_val - 63)) * LOG10_2 - 0.69));
}