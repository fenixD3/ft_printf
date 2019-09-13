//
// Created by Yeste Lila on 2019-09-12.
//
#include "float.h"

char	*print_inf_nan(t_dbls dbl)
{
	if (!dbl.mant)
		return (dbl.sign ? "-inf" : "+inf");
	return (dbl.sign ? "-nan" : "+nan");
}

char	*print_zero(t_dbls dbl)
{
	return (dbl.sign ? "-0" : "+0");
}