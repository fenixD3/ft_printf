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
			return (print_zero(res, tools));
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

static void	process(t_result *res, t_high *hp, const t_dbl_comp *dblcomp, t_prsng *tools)
{
	insert_low_bits(hp, dblcomp->mant_High_Bits, dblcomp->exp_val + 12, 1);
	insert_low_bits(hp, dblcomp->mant_Low_Bits, dblcomp->exp_val - 32 + 12, 1);
	fill_result(hp, 1, tools->precision, res);
	if (tools->precision || tools->flags & M_PRECISION_NOT_ADDED || tools->flags & M_SHARP)
	{
		ft_strncat(res->result, ".", 1);
		++res->len;
	}
	insert_top_bits(hp, dblcomp->mant_High_Bits, 52 - dblcomp->exp_val - 32, 0);
	insert_top_bits(hp, dblcomp->mant_Low_Bits, 52 - dblcomp->exp_val, 0);
	fill_result(hp, 0, tools->precision, res);
}

char		*print_double(t_prsng *tools,  t_mkfld *fld, double number)
{
	t_dbl_comp	dblcomp;
	t_high		*hp;
	t_result	res;
	int32_t		lg_10;

	res.len = -1;
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
	process(&res, hp, &dblcomp, tools);
	check_result(&res);
	return (res.result);
}
