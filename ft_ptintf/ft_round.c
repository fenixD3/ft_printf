//
// Created by da.filiptsev on 25.11.2019.
//

#include "ft_ptintf.h"

double		ft_round(double num)
{
	double	floor;
	double	ceil;

	floor = ft_floor(num);
	ceil = ft_ceil(num);
	if (num - floor == ceil - num  && num > 0)
		return (ceil);
	else if (num - floor == ceil - num  && num < 0)
		return (floor);
	if (num - floor < ceil - num)
		return (floor);
	return (ceil);
}

long double	ft_roundl(long double num)
{
	long double	floor;
	long double	ceil;

	floor = ft_floor(num);
	ceil = ft_ceil(num);
	if (num - floor == ceil - num  && num > 0)
		return (ceil);
	else if (num - floor == ceil - num  && num < 0)
		return (floor);
	if (num - floor < ceil - num)
		return (floor);
	return (ceil);
}
