#include "myfloat.h"
#include "high_precision.h"
#include "ft_ptintf.h"

static char	*initialize_dbl(t_dbl_comp *dblcomp, double number)
{
	uint64_t	*dbl;

	dbl = (uint64_t *)&number;
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

static char	*initialize_ldbl(t_dbl_comp *ldblcomp, long double number)
{
	uint64_t	*ldbl;

	ldbl = (uint64_t *)&number;
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

/// (uint32_t)ft_ceil(((int32_t)ft_64log2(dblcomp.mant_val) + (dblcomp.exp_val - 52)) * LOG10_2)
/// tools->precision should be used for malloc result
char		*print_double(t_prsng *tools,  t_mkfld *fld, double number)
{
	/// tools->flag & (#,' ') tools->precision точность число
	/// в fld->lennum записать общий размер строки
	t_dbl_comp	dblcomp;
	t_high		*hp;
	char		*result;
	int32_t		lg_10;

	if ((result = initialize_dbl(&dblcomp, number)))
		return (result);
	lg_10 = ft_log10(dblcomp.mant_val, dblcomp.exp_val);
	printf("Log 10 = %d\n", lg_10);
	//printf("Log10 = %d\n", (int32_t)ft_ceil(((int32_t)ft_64log2(dblcomp.mant_val) + (dblcomp.exp_val - 52)) * LOG10_2 - 0.69));
	hp = hp_initializ();
	insert_low_bits(hp, dblcomp.mant_High_Bits, dblcomp.exp_val + 12, 1);
	insert_low_bits(hp, dblcomp.mant_Low_Bits, dblcomp.exp_val - 32 + 12, 1);
	result = ft_strnew(5000);
	//// protect
	dblcomp.sign ? ft_strncpy(result, "-", 1) : result;
	fill_result(result, hp, 1);
	ft_strncat(result, ".", 1);
	insert_top_bits(hp, dblcomp.mant_High_Bits, 52 - dblcomp.exp_val - 32, 0);
	insert_top_bits(hp, dblcomp.mant_Low_Bits, 52 - dblcomp.exp_val, 0);
	fill_result(result, hp, 0);
	return (result);
}

char		*print_long_double(t_prsng *tools, t_mkfld *fld, long double number)
{
	t_dbl_comp	ldblcomp;
	t_highl		*hp;
	char		*result;
	int32_t		lg_10;

	if ((result = initialize_ldbl(&ldblcomp, number)))
		return (result);
	lg_10 = ft_llog10(ldblcomp.mant_val, ldblcomp.exp_val);
	printf("Log 10 = %d\n", lg_10);
	//printf("Log10 = %d\n", (int32_t)ft_ceill(((int32_t)ft_64log2(ldblcomp.mant_val) + (ldblcomp.exp_val - 63)) * LOG10_2 - 0.69));
	hp = hp_ldbl_initializ();
	/// protect
	insert_low_lbits(hp, ldblcomp.mant_High_Bits, ldblcomp.exp_val + 1, 1);
	insert_low_lbits(hp, ldblcomp.mant_Low_Bits, ldblcomp.exp_val - 32 + 1, 1);
	result = ft_strnew(20000);
	ldblcomp.sign ? ft_strncpy(result, "-", 1) : result;
	fill_lresult(result, hp, 1);
	ft_strncat(result, ".", 1);
	insert_top_lbits(hp, ldblcomp.mant_High_Bits, 63 - ldblcomp.exp_val - 32, 0);
	insert_top_lbits(hp, ldblcomp.mant_Low_Bits, 63 - ldblcomp.exp_val, 0);
	fill_lresult(result, hp, 0);
	return (result);
}
