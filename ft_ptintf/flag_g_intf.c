//
// Created by da.filiptsev on 06.12.2019.
//

#include "myfloat.h"

static void	delete_lst_zero(char *res_f, char *res_e, size_t *l_f, size_t *l_e)
{
	size_t	len_f;
	size_t	len_e;

	len_f = *l_f;
	len_e = *l_e;
	while (*(res_f + (--len_f)))
		;
}

char		*compaing_f_e(char *res_f, char *res_e)
{
	size_t	len_f;
	size_t	len_e;

	len_f = ft_strlen(res_f);
	len_e = ft_strlen(res_e);
	delete_lst_zero(res_f, res_e, &len_f, &len_e);
}
