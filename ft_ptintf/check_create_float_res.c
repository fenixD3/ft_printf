//
// Created by Yeste Lila on 2019-11-30.
//

#include "myfloat.h"
#include "libft/libft.h"

static void	create_for_e(t_prsng *tools, size_t *lennum)
{
	if (tools->precision)
		*lennum = 1 + tools->precision;
	else if (tools->flags & M_PRECISION_NOT_ADDED)
	{
		*lennum = 1 + 6;
		tools->precision = 6;
	}
	else
		*lennum = 1;
}

t_result	create_str(const int32_t lg_10, t_prsng *tools, t_mkfld *fld)
{
	t_result	res;
	size_t		lennum;

	if (tools->type == 'e' || tools->type == 'E')
		create_for_e(tools, &lennum);
	else if (tools->precision)
		lennum = (lg_10 > 0) ? lg_10 + tools->precision : 1 + tools->precision;
	else if (tools->flags & M_PRECISION_NOT_ADDED)
	{
		lennum = (lg_10 > 0) ? lg_10 + 6 : 1 + 6;
		tools->precision = 6;
	}
	else
		lennum = (lg_10 > 0) ? lg_10: 1;
	if (tools->flags & M_SHARP || tools->precision || tools->flags & M_PRECISION_NOT_ADDED)
		++lennum;
	if (tools->type == 'e' || tools->type == 'E')
		lennum += (lg_10 >= 0) ? 1 + ft_strlen(ft_itoa(lg_10)) + 1 : 1 + ft_strlen(ft_itoa(lg_10)) ;
	if (!(res.result = ft_strnew(lennum + 1)))
		return ((t_result){NULL, NULL, 0});
	*res.result = '0';
	res.begin = res.result;
	++res.result;
	fld->lennum = lennum;
	return (res);
}

void	check_result(t_result *res)
{
	if (res->result != res->begin)
	{
		res->begin = ft_strnew(res->len);
		ft_strncpy(res->begin, res->result, res->len);
		free(--res->result);
		res->result = res->begin;
	}
	return ;
}
