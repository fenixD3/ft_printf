//
// Created by da.filiptsev on 13.11.2019.
//

#include "libft/libft.h"
#include "myfloat.h"

char		*print_nan(t_result *res, const char type)
{
	if (!(res->result = ft_strnew(4)))
	{
		res->len = 0;
		return (NULL);
	}
	if (type == 'F')
		return (ft_strcpy(res->result, "NAN"));
	return (ft_strcpy(res->result, "nan"));
}

char		*print_inf(t_result *res, _Bool sign, const char type)
{
	if (!(res->result = ft_strnew(4)))
	{
		res->len = 0;
		return (NULL);
	}
	if (type == 'F')
		return (sign ? ft_strcpy(res->result, "-INf") : ft_strcpy(res->result, "INf"));
	return (sign ? ft_strcpy(res->result, "-inf") : ft_strcpy(res->result, "inf"));
}

char		*print_zero(t_result *res, _Bool sign)
{
	if (!(res->result = ft_strnew(2)))
	{
		res->len = 0;
		return (NULL);
	}
	return (sign ? ft_strcpy(res->result, "-0") : ft_strcpy(res->result, "+0"));
}