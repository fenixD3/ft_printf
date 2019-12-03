//
// Created by Yeste Lila on 2019-11-30.
//

#include "myfloat.h"
#include "libft/libft.h"

static void	round_intg_nearest(t_result *res, const int nxt_nu)
{
	size_t	i;
	int 	nu;

	i = 0;
	if (*(res->result + res->len - (++i)) == '.')
		++i;
	if (nxt_nu == 5)
	{
		nu = atoi(res->result + res->len - i);
		if (nu == 9)
		{
			*(res->result + res->len - i) = '0';
			while (*(res->result + res->len - ++i) == '9')
				*(res->result + res->len - i) = '0';
			++*(res->result + res->len - i);
		}
		else if (nu % 2)
			++*(res->result + res->len - i);
	}
	else
	{
		while (*(res->result + res->len - i) == '9')
			*(res->result + res->len - i++) = '0';
		++*(res->result + res->len - i);
	}
}

static void	precision_rounding(t_result *res)
{
	size_t	i;

	i = 0;
	while (*(res->result + res->len - ++i) == '9' || *(res->result + res->len - i) == '.')
	{
		if (*(res->result + res->len - i) == '.')
			continue ;
		*(res->result + res->len - i) = '0';
	}
	++*(res->result + res->len - i);
}

void		float_round(t_result *res, const int nxt_nu, const int prec)
{
	if (!prec)
		round_intg_nearest(res, nxt_nu);
	else
		precision_rounding(res);
}
