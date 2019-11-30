//
// Created by Yeste Lila on 2019-11-30.
//

#include "myfloat.h"
#include "libft/libft.h"

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