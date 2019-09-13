#include "float.h"

char	*get_double(double num)
{
	// 11 bit exp, 52 bit mant
	t_dbls		dbl;

	dbl.sign = num & 1 << 63 ? 1 : 0;
	dbl.exp = (num >> 52) & 0x7FF;
	dbl.mant = num & 0xFFFFFFFFFFFFF;
	if (dbl.exp == 0x7FF)
		return print_inf_nan(dbl);
	else if (!dbl.exp && !dbl.mant)
		return print_zero(dbl);
}

char	*get_ldouble(long double num)
{
	// 15 bit exp, 63 bit mant or 64 bit mant + first 1
	t_dbls		dbl;

	dbl.sign = num & 1 << 79 ? 1 : 0;
	dbl.exp = (num >> 64) & 0x7FFF;
	dbl.mant = num & 0x7FFFFFFFFFFFFFFF;
	if (dbl.exp == 0x7FFF)
		return print_inf_nan();
	else if (!dbl.exp && !dbl.mant)
		return print_zero();
}
