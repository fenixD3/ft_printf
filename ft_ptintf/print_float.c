//
// Created by Yeste Lila on 2019-09-12.
//
#include "float.h"
#include "ft_ptintf.h"

inline char	*print_inf_nan(t_dbls dbl)
{
	if (!dbl.mant)
		return (dbl.sign ? "-inf" : "+inf");
	return (dbl.sign ? "-nan" : "+nan");
}

inline char	*print_zero(t_dbls dbl)
{
	return (dbl.sign ? "-0" : "+0");
}

char	*print_positional(t_dbls dbl, t_prsng tools)
{
	;
}

char	*print_scientific(t_dbls dbl, t_prsng tools)
{
	;
}

char	*print_rounded(t_dbls dbl, t_prsng tools)
{
	;
}

char	*print_heximal(t_dbls dbl, t_prsng tools)
{
	;
}
