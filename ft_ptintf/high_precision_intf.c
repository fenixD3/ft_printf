//
// Created by da.filiptsev on 14.11.2019.
//

#include "high_precision.h"
#include "ft_ptintf.h"

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

static void	fill_result_fract(char *result, t_high *hp, _Bool intg, int precision)
{
	char	rem_overf;

	while (precision-- && !hp_is_zero(hp, intg))
	{
		rem_overf = mul_ret_overflow(hp, 10) + '0';
		ft_strncat(result, &rem_overf, 1);
	}
	if (mul_ret_overflow(hp, 10) >= 5)
	{
		;
	}
	else if (precision)
		while (precision--)
			ft_strncat(result, "0", 1);
}

static void	fill_result_intg(char *result, t_high *hp, _Bool intg, int precision)
{
	char	rem_overf;

	rem_overf = div_ret_remainder(hp, 10) + '0';
	ft_strncat(result, &rem_overf, 1);
	while (!hp_is_zero(hp, intg))
	{
		rem_overf = div_ret_remainder(hp, 10) + '0';
		ft_strncat(result, &rem_overf, 1);
	}
	if (*result == '-')
		ft_reverse(result + 1);
	else
		ft_reverse(result);
}

void		fill_result(char *result, t_high *hp, _Bool intg, int precision)
{
	if (intg)
		fill_result_intg(result, hp, intg, precision);
	else
		fill_result_fract(result, hp, intg, precision);
}
