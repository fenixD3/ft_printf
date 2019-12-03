//
// Created by Yeste Lila on 2019-11-22.
//

#include "high_precision.h"
#include "ft_ptintf.h"

t_highl		*hp_ldbl_initializ(void)
{
	t_highl	*new;

	if (!(new = (t_highl *)malloc(sizeof(t_highl))))
		return (NULL);
	ft_memcpy(new, &(t_highl){{0}, {0}, 32, 1}, sizeof(*new));
	return (new);
}

_Bool		hp_is_lzero(t_highl *hp, _Bool intg)
{
	size_t i;

	i = 0;
	if (intg)
	{
		while (i < ARRSIZE_INTG_LDBL)
			if (hp->data_intg[i++] != 0)
				return (0);
	}
	else
		while (i < ARRSIZE_FRCT_LDBL)
			if (hp->data_frct[i++] != 0)
				return (0);
	return (1);
}

static void	fill_lresult_fract(t_highl *hp, _Bool intg, int precision, t_result *res)
{
	char	rem_overf;
	int		nxt_nu;
	int		prec;

	ft_memcpy(&prec, &precision, sizeof(int));
	while (precision > 0 && !hp_is_lzero(hp, intg))
	{
		rem_overf = mul_ret_loverflow(hp, 10) + '0';
		ft_strncat(res->result, &rem_overf, 1);
		++res->len;
		--precision;
	}
	if (precision <= 0 && (nxt_nu = mul_ret_loverflow(hp, 10)) >= 5)
		float_round(res, nxt_nu, prec);
	else
		while (precision-- > 0)
		{
			ft_strncat(res->result, "0", 1);
			++res->len;
		}
}

static void	fill_lresult_intg(t_highl *hp, _Bool intg, t_result *res)
{
	char	rem_overf;

	rem_overf = div_ret_lremainder(hp, 10) + '0';
	ft_strncat(res->result, &rem_overf, 1);
	++res->len;
	while (!hp_is_lzero(hp, intg))
	{
		rem_overf = div_ret_lremainder(hp, 10) + '0';
		ft_strncat(res->result, &rem_overf, 1);
		++res->len;
	}
	ft_reverse(res->result);
}

void		fill_lresult(t_highl *hp, _Bool intg, int precision, t_result *res)
{
	if (intg)
	{
		res->len = 0;
		fill_lresult_intg(hp, intg, res);
	}
	else
		fill_lresult_fract(hp, intg, precision, res);
}