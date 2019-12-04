//
// Created by da.filiptsev on 14.11.2019.
//

#include "high_precision.h"
#include "ft_ptintf.h"
#include "myfloat.h"

t_high		*hp_initializ(void)
{
	t_high	*new;

	if (!(new = (t_high *)malloc(sizeof(t_high))))
		return (NULL);
	ft_memcpy(new, &(t_high){{0}, {0}, 32, 1}, sizeof(*new));
	return (new);
}

_Bool		hp_is_zero(t_high *hp, _Bool intg)
{
	size_t i;

	i = 0;
	if (intg)
	{
		while (i < ARRSIZE_INTG_DBL)
			if (hp->data_intg[i++] != 0)
				return (0);
	}
	else
		while (i < ARRSIZE_FRCT_DBL)
			if (hp->data_frct[i++] != 0)
				return (0);
	return (1);
}

static void	fill_result_fract(t_high *hp, _Bool intg, int precision, t_result *res)
{
	char	rem_overf;
	int		nxt_nu;
	int		prec;

	ft_memcpy(&prec, &precision, sizeof(int));
	while (precision > 0 && !hp_is_zero(hp, intg))
	{
		rem_overf = mul_ret_overflow(hp, 10) + '0';
		ft_strncat(res->result, &rem_overf, 1);
		++res->len;
		--precision;
	}
	if (precision <= 0 && (nxt_nu = mul_ret_overflow(hp, 10)) >= 5)
		float_round(res, nxt_nu, prec);
	else
		while (precision-- > 0)
		{
			ft_strncat(res->result, "0", 1);
			++res->len;
		}
}

static void	fill_result_intg(t_high *hp, _Bool intg, t_result *res, char type)
{
	char		rem_overf;

	rem_overf = div_ret_remainder(hp, 10) + '0';
	ft_strncat(res->buff, &rem_overf, 1);
	++res->len;
	while (!hp_is_zero(hp, intg))
	{
		rem_overf = div_ret_remainder(hp, 10) + '0';
		ft_strncat(res->buff, &rem_overf, 1);
		++res->len;
	}
	ft_reverse(res->buff);
	if (type == 'e' || type == 'E')
		check_e_intg_res(res);
	else
	{
		ft_strncpy(res->result, res->buff, res->len);
		free(res->buff);
		res->buff = NULL;
	}
}

void		fill_result(t_high *hp, _Bool intg, t_prsng *tools, t_result *res)
{
	if (intg)
	{
		res->len = 0;
		fill_result_intg(hp, intg, res, tools->type);
	}
	else
	{
		if (res->buff)
		{
			while (res->buff && tools->precision--)
				ft_strncpy(res->result, ++res->buff, 1);
		}
		fill_result_fract(hp, intg, tools->precision, res);
	}
}
