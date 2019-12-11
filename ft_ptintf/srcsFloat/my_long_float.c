/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_long_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 22:38:40 by ylila             #+#    #+#             */
/*   Updated: 2019/12/10 22:44:34 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfloat.h"
#include "high_precision.h"

static char	*initialize_ldbl(t_result *res, t_dbl_comp *ldblcomp,
		long double number, t_prsng *tools)
{
	uint64_t	*ldbl;

	ldbl = (uint64_t *)&number;
	ldblcomp->sign = get_lsign(ldbl);
	if ((ldblcomp->exp_val = get_lexp(ldbl)) == 0x7fff)
	{
		if (!get_lmantissa(ldbl))
			return (print_inf(res, ldblcomp->sign, tools->type));
		return (print_nan(res, tools->type));
	}
	if (!ldblcomp->exp_val)
	{
		if (!get_lmantissa(ldbl))
			return (print_zero(res, ldblcomp->sign, tools));
		ldblcomp->exp_val = 1 - offset_ldbl;
		ldblcomp->mant_val = get_lmantissa(ldbl);
	}
	else
	{
		ldblcomp->exp_val -= offset_ldbl;
		ldblcomp->mant_val = get_lmantissa(ldbl);
	}
	ldblcomp->mant_high_bits = ldblcomp->mant_val >> 32;
	ldblcomp->mant_low_bits = ldblcomp->mant_val & 0xffffffff;
	return (null);
}

static void	process(t_result *res, t_highl *hp, const t_dbl_comp *ldblcomp,
		t_prsng *tools)
{
	insert_low_lbits(hp, ldblcomp->mant_high_bits, ldblcomp->exp_val + 1, 1);
	insert_low_lbits(hp, ldblcomp->mant_low_bits,
			ldblcomp->exp_val - 32 + 1, 1);
	fill_lresult(hp, 1, tools, res);
	if (*res->result)
		add_point(res, tools);
	insert_top_lbits(hp, ldblcomp->mant_high_bits,
			63 - ldblcomp->exp_val - 32, 0);
	insert_top_lbits(hp, ldblcomp->mant_low_bits, 63 - ldblcomp->exp_val, 0);
	res->bf_len = 0;
	fill_lresult(hp, 0, tools, res);
	if (tools->type == 'e' || tools->type == 'e')
		fill_exp_chars(res, tools->type);
}

char		*print_long_double(t_prsng *tools, t_mkfld *fld, long double number)
{
	t_dbl_comp	ldblcomp;
	t_highl		*hp;
	t_result	res;
	int			precision;

	res.len = -1;
	if ((res.result = initialize_ldbl(&res, &ldblcomp, number, tools)))
		return (res.result);
	if (!res.len)
		return (null);
	res.lg_10 = ft_floor(ft_log10(number));
	if (ft_tolower(tools->type) == 'g' || ft_tolower(tools->type) == 'a')
		return (calculate_g_a_result(tools, fld, res.lg_10));
	if (!(hp = hp_ldbl_initializ()))
		return (null);
	res = create_str(res.lg_10, tools, fld);
	precision = tools->prec;
	if (!res.result)
		return (null);
	process(&res, hp, &ldblcomp, tools);
	check_result(&res, tools, precision, fld);
	if (!res.len)
		return (null);
	free_l_hp(hp);
	return (res.result);
}
