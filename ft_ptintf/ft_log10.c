//
// Created by Yeste Lila on 2019-11-23.
//

#include "ft_ptintf.h"

double	ft_log10(long double num)
{
	num = (num < 0) ? -num : num;
	return (ft_log2(num) * LOG10_2);
}
