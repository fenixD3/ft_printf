//
// Created by da.filiptsev on 05.12.2019.
//

#include "myfloat.h"

void	check_e_intg_res(t_result *res)
{
	if (*res->buff == '0')
		clear_res_buff(res);
	else if (res->bf_len > 1)
	{
		ft_strncpy(res->result, res->buff, 1);
		++res->len;
	}
}

void	fill_exp_chars(t_result *res, const char type)
{
	char	*num_str;
	size_t	size_num_str;

	type == 'e' ? ft_strncat(res->result, "e", 1) : ft_strncat(res->result, "E", 1);
	++res->len;
	num_str = ft_itoa(ABS(res->lg_10));
	size_num_str = ft_strlen(num_str);
	res->lg_10 >= 0 ? ft_strncat(res->result, "+", 1) : ft_strncat(res->result, "-", 1);
	++res->len;
	if (ABS(res->lg_10) >= 0 && ABS(res->lg_10) <= 9)
	{
		ft_strncat(res->result, "0", 1);
		++res->len;
	}
	ft_strncat(res->result, num_str, size_num_str);
	res->len += size_num_str;
}

void	add_point(t_result *res, t_prsng *tools)
{
	if (tools->precision || tools->flags & M_PRECISION_NOT_ADDED || tools->flags & M_SHARP)
	{
		ft_strncat(res->result, ".", 1);
		++res->len;
	}
}

void	fill_fucking_first_char(t_result *res, t_prsng *tools)
{
	;
}