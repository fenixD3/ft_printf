#include "myfloat.h"
#include "high_precision.h"
#include "ft_ptintf.h"

static char	*initialize_dbl(t_result *res, t_dbl_comp *dblcomp, double number, t_prsng *tools)
{
	uint64_t	*dbl;

	dbl = (uint64_t *)&number;
	dblcomp->sign = get_sign(dbl);
	if ((dblcomp->exp_val = get_exp(dbl)) == 0x7FF)
	{
		if (!get_mantissa(dbl))
			return (print_inf(res, dblcomp->sign, tools->type));
		return (print_nan(res, tools->type));
	}
	if (!dblcomp->exp_val)
	{
		if (!get_mantissa(dbl))
			return (print_zero(res, dblcomp->sign));
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

/*static char	*initialize_ldbl(t_dbl_comp *ldblcomp, long double number)
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
}*/

static t_result	create_str(const int32_t lg_10, t_prsng *tools, t_mkfld *fld)
{
	t_result	res;
	size_t		lennum;

	if (tools->precision)
		lennum = (lg_10 > 0) ? lg_10 + tools->precision : 1 + tools->precision;
	else if (tools->flags & M_PRECISION_NOT_ADDED)
	{
		lennum = (lg_10 > 0) ? lg_10 + 6 : 1 + 6;
		tools->precision = 6;
	}
	else
		lennum = (lg_10 > 0) ? lg_10: 1;
	if (tools->flags & M_SHARP || tools->precision || tools->flags & M_PRECISION_NOT_ADDED)
		++lennum;
	if (!(res.result = ft_strnew(lennum + 1)))
		return ((t_result){NULL, NULL, 0});
	*res.result = '0';
	res.begin = res.result;
	++res.result;
	fld->lennum = lennum;
	return (res);
}

/// (uint32_t)ft_ceil(((int32_t)ft_64log2(dblcomp.mant_val) + (dblcomp.exp_val - 52)) * LOG10_2)
/// tools->precision should be used for malloc result
/// tools->type contains type of parameter
char		*print_double(t_prsng *tools,  t_mkfld *fld, double number)
{
	/// tools->flag & (#,' ') tools->precision точность число
	/// в fld->lennum записать общий размер строки
	t_dbl_comp	dblcomp;
	t_high		*hp;
	t_result	res;
	int32_t		lg_10;

	if ((res.result = initialize_dbl(&res, &dblcomp, number, tools)))
		return (res.result);
	if (!res.len)
		return (NULL);
	lg_10 = ft_floor(ft_log10(number));
	if (!(hp = hp_initializ()))
		return (NULL);
	res = create_str(lg_10, tools, fld);
	if (!res.result)
		return (NULL);
	insert_low_bits(hp, dblcomp.mant_High_Bits, dblcomp.exp_val + 12, 1);
	insert_low_bits(hp, dblcomp.mant_Low_Bits, dblcomp.exp_val - 32 + 12, 1);
	fill_result(hp, 1, tools->precision, &res);
	if (tools->precision || tools->flags & M_PRECISION_NOT_ADDED || tools->flags & M_SHARP)
	{
		ft_strncat(res.result, ".", 1);
		++res.len;
	}
	insert_top_bits(hp, dblcomp.mant_High_Bits, 52 - dblcomp.exp_val - 32, 0);
	insert_top_bits(hp, dblcomp.mant_Low_Bits, 52 - dblcomp.exp_val, 0);
	fill_result(hp, 0, tools->precision, &res);
	check_result(&res);
	return (res.result);
}

/*char		*print_long_double(t_prsng *tools, t_mkfld *fld, long double number)
{
	t_dbl_comp	ldblcomp;
	t_highl		*hp;
	char		*res;
	int32_t		lg_10;

	if ((res = initialize_ldbl(&ldblcomp, number)))
		return (res);
	//lg_10 = ft_llog10(ldblcomp.mant_val, ldblcomp.exp_val);
	if (!(hp = hp_ldbl_initializ()))
		return (NULL);
	insert_low_lbits(hp, ldblcomp.mant_High_Bits, ldblcomp.exp_val + 1, 1);
	insert_low_lbits(hp, ldblcomp.mant_Low_Bits, ldblcomp.exp_val - 32 + 1, 1);
	if (!(res = ft_strnew(20000)))
		return (NULL);
	ldblcomp.sign ? ft_strncpy(res, "-", 1) : res;
	fill_lresult(res, hp, 1);
	ft_strncat(res, ".", 1);
	insert_top_lbits(hp, ldblcomp.mant_High_Bits, 63 - ldblcomp.exp_val - 32, 0);
	insert_top_lbits(hp, ldblcomp.mant_Low_Bits, 63 - ldblcomp.exp_val, 0);
	fill_lresult(res, hp, 0);
	return (res);
}*/
