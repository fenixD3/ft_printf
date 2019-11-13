#include "myfloat.h"
#include "high_precision.h"
#include "ft_ptintf.h"

/// tools->precision should use for malloc result
char	*initialize_dbl(t_double *dbl, t_dbl_comp *dblcomp, double number)
{
	dbl->num = number;
	dblcomp->sign = get_sign(dbl);
	if ((dblcomp->exp_val = get_exp(dbl)) == 0x7FF)
	{
		if (!get_mantissa(dbl))
			return (print_inf(dblcomp->sign));
		return (print_nan(dblcomp->sign));
	}
	if (!dblcomp->exp_val)
	{
		if (!get_mantissa(dbl))
			return (print_zero(dblcomp->sign));
		dblcomp->exp_val = 1 - OFFSET_DBL;
		dblcomp->mant_val = get_mantissa(dbl);
	}
	else
	{
		dblcomp->exp_val -= OFFSET_DBL;
		dblcomp->mant_val = (1LL << 52) | get_mantissa(dbl);
	}
	dblcomp->mant_High_Bits = dblcomp->mant_val >> 32;
	dblcomp->mant_Low_Bits = dblcomp->mant_val & 0xFFFFFFFF;
	return (NULL);
}

char	*PrintDouble(t_prsng *tools, double number)
{
	t_double	dbl;
	t_dbl_comp	dblcomp;
	char		*result;

	if (result = initialize_dbl(&dbl, &dblcomp, number))
		return (result);
	/// write fucking HighPrecision Class
	hp_initialz(0);
}