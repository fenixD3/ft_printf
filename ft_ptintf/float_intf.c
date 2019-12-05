//
// Created by Yeste Lila on 2019-12-05.
//

#include "high_precision.h"

void	add_point(t_result *res, t_prsng *tools)
{
	if (tools->precision || tools->flags & M_PRECISION_NOT_ADDED || tools->flags & M_SHARP)
	{
		ft_strncat(res->result, ".", 1);
		++res->len;
	}
}
