#include "myfloat.h"
#include "high_precision.h"
#include "ft_ptintf.h"

static char	*initialize_dbl(t_double *dbl, t_dbl_comp *dblcomp, double number)
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

static char	*initialize_l_dbl(t_dbl_comp *ldblcomp, long double number)
{
	uint64_t	*ldbl;

	ldbl = &number;
	ldblcomp->sign = get_lsign(ldbl);
	if ((ldblcomp->exp_val = get_lexp(ldbl)) == 0x7FFF)
	{
		if (!get_lmantissa(ldbl))
			return (print_inf(ldblcomp->sign));
		return (print_nan(ldblcomp->sign));
	}
	if (!ldblcomp->exp_val)
	{
		if (!get_lmantissa(ldbl))
			return (print_zero(ldblcomp->sign));
		ldblcomp->exp_val = 1 - OFFSET_LDBL;
		ldblcomp->mant_val = get_lmantissa(ldbl);
	}
	else
	{
		ldblcomp->exp_val -= OFFSET_LDBL;
		ldblcomp->mant_val = get_lmantissa(ldbl);
	}
	ldblcomp->mant_High_Bits = ldblcomp->mant_val >> 32;
	ldblcomp->mant_Low_Bits = ldblcomp->mant_val & 0xFFFFFFFF;
	return (NULL);
}

/// tools->precision should use for malloc result
char		*print_double(t_prsng *tools, double number)
{
	t_double	dbl;
	t_dbl_comp	dblcomp;
	t_high		*hp;
	char		*result;

	if ((result = initialize_dbl(&dbl, &dblcomp, number)))
		return (result);
	hp = hp_initializ();
	insert_low_bits(hp, dblcomp.mant_High_Bits, dblcomp.exp_val + 12, 1);
	insert_low_bits(hp, dblcomp.mant_Low_Bits, dblcomp.exp_val - 32 + 12, 1);
	result = ft_strnew(5000);
	dblcomp.sign ? ft_strncpy(result, "-", 1) : result;
	fill_result(result, hp, 1);
	ft_strncat(result, ".", 1);
	insert_top_bits(hp, dblcomp.mant_High_Bits, 52 - dblcomp.exp_val - 32, 0);
	insert_top_bits(hp, dblcomp.mant_Low_Bits, 52 - dblcomp.exp_val, 0);
	fill_result(result, hp, 1);
	return (result);
}

char		*print_long_double(t_prsng *tools, long double number)
{
	t_dbl_comp	ldblcomp;
	t_high		*hp;
	char		*result;

	if ((result = initialize_l_dbl(&ldblcomp, number)))
		return (result);
}