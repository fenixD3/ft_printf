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
	t_high		*hp;
	char		rem_owerf;
	char		*result;

	if (result = initialize_dbl(&dbl, &dblcomp, number))
		return (result);
	hp = hp_initializ();
	insert_low_bits(hp, dblcomp.mant_High_Bits, dblcomp.exp_val + 12, 1);
	insert_low_bits(hp, dblcomp.mant_Low_Bits, dblcomp.exp_val - 32 + 12, 1);
	result = ft_strnew(5000);
	dblcomp.sign ? ft_strncpy(result, "-", 1) : ft_strncpy(result, "+", 1);
	rem_owerf = div_ret_remainder(hp, 10) + '0';
	ft_strncat(result, &rem_owerf, 1);
	while (!hp_is_zero(hp, 1))
	{
		rem_owerf = div_ret_remainder(hp, 10) + '0';
		ft_strncat(result, &rem_owerf, 1);
	}
	ft_strncat(result, ".", 1);
	insert_top_bits(hp, dblcomp.mant_High_Bits, 52 - dblcomp.exp_val - 32, 0);
	insert_top_bits(hp, dblcomp.mant_Low_Bits, 52 - dblcomp.exp_val, 0);
	while (!hp_is_zero(hp, 0))
	{
		rem_owerf = mul_ret_overflow(hp, 10) + '0';
		ft_strncat(result, &rem_owerf, 1);
	}
	return (result);
}