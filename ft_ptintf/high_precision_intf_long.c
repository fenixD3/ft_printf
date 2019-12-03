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

char		*fill_lresult(char *result, t_highl *hp, _Bool intg)
{
	char	rem_overf;

	if (intg)
	{
		rem_overf = div_ret_lremainder(hp, 10) + '0';
		ft_strncat(result, &rem_overf, 1);
		while (!hp_is_lzero(hp, intg))
		{
			rem_overf = div_ret_lremainder(hp, 10) + '0';
			ft_strncat(result, &rem_overf, 1);
		}
		if (*result == '-')
			ft_reverse(result + 1);
		else
			ft_reverse(result);
	}
	else
	{
		while (!hp_is_lzero(hp, intg))
		{
			rem_overf = mul_ret_loverflow(hp, 10) + '0';
			ft_strncat(result, &rem_overf, 1);
		}
	}
	return (result);
}