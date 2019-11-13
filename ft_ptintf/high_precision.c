//
// Created by da.filiptsev on 13.11.2019.
//

#include "high_precision.h"

t_high	hp_initialz(_Bool intg)
{
	t_high	new;

	if (intg)
		ft_memset(new.data_intg, 0, sizeof(new.data_intg));
	else
		ft_memset(new.data_frct, 0, sizeof(new.data_frct));
	return (new);
}

_Bool	is_zero(t_high *hp, _Bool intg)
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