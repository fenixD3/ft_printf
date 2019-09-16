#include "float.h"
#include "ft_ptintf.h"

char	*get_double(double num, t_prsng tools)
{
	// 11 bit exp, 52 bit mant
	t_dbls		dbl;

	dbl.sign = num & 1 << 63 ? 1 : 0;
	dbl.exp = (num >> 52) & 0x7FF;
	dbl.mant = num & 0xFFFFFFFFFFFFF;
	if (dbl.exp == 0x7FF)
		return (print_inf_nan(dbl));
	else if (!dbl.exp && !dbl.mant)
		return (print_zero(dbl));
	if (!dbl.exp)
	{
		dbl.val_mant = dbl.mant;
		dbl.val_exp = 1 - OFFSET64 - 52;
	}
	else
	{
		dbl.val_mant = (1 << 52) | dbl.mant;
		dbl.val_exp = dbl.exp - OFFSET64 - 52;
	}
	if (tools.type == 'f' || tools.type == 'F')
		return (print_positional(dbl, tools));
	if (tools.type == 'e' || tools.type == 'E')
		return (print_scientific(dbl, tools));
	if (tools.type == 'g' || tools.type == 'G')
		return (print_rounded(dbl, tools));
	if (tools.type == 'a' || tools.type == 'A')
		return (print_heximal(dbl, tools));
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
	if (!dbl.exp)
	{
		dbl.val_mant = dbl.mant;
		dbl.val_exp = 1 - OFFSET80 - 63;
	}
	else
	{
		dbl.val_mant = (1 << 63) | dbl.mant;
		dbl.val_exp = dbl.exp - OFFSET80 - 63;
	}
	if (tools.type == 'f' || tools.type == 'F')
		return (print_positional(dbl, tools));
	if (tools.type == 'e' || tools.type == 'E')
		return (print_scientific(dbl, tools));
	if (tools.type == 'g' || tools.type == 'G')
		return (print_rounded(dbl, tools));
	if (tools.type == 'a' || tools.type == 'A')
		return (print_heximal(dbl, tools));
}
