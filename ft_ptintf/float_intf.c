//
// Created by Yeste Lila on 2019-12-05.
//

#include "high_precision.h"

void		add_point(t_result *res, t_prsng *tools)
{
	if (tools->precision || tools->flags & M_PRECISION_NOT_ADDED || tools->flags & M_SHARP)
	{
		ft_strncat(res->result, ".", 1);
		++res->len;
	}
}

char		*calculate_g_a_result(t_prsng *tools, t_mkfld *fld)
{
	char	*res_f;
	char 	*res_e;

	if (ft_tolower(tools->type) == 'g')
	{
		tools->type = (tools->type == 'g') ? 'f' : 'F';
		if (tools->modifiers & M_UPPER_L)
			res_f = print_long_double(tools, fld, fld->number.ldb);
		else
			res_f = print_double(tools, fld, fld->number.ldb);
		tools->type = (tools->type == 'g') ? 'e' : 'E';
		if (tools->modifiers & M_UPPER_L)
			res_e = print_long_double(tools, fld, fld->number.ldb);
		else
			res_e = print_double(tools, fld, fld->number.ldb);
		return (compaing_f_e(res_f, res_e));
	}
	else
		; /// a_flag
}